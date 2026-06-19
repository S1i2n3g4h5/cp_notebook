import time
import numpy as np
import plotly.graph_objects as go
from IPython.display import clear_output

# --- CONFIGURABLE PARAMETERS ---
TORNADO_LIFESPAN_MINS = 3
WIDTH_RATIO = 0.25             # Circle width is exactly 25% of the price range
BASE_PRICE = 150.00
PRICE_RANGE_SPAN = 6.0         # Total vertical window size ($147 to $153)

# Simulation Timing Controls (Compressed for quick rendering in Colab)
TOTAL_STEPS = 90               # 90 frame updates total
CONSOLIDATION_STEPS = 60       # First 2 minutes (60 steps) -> Tight ranging
DROP_STEPS = 30                # Last 1 minute (30 steps)  -> Fast $2 drop
FRAME_DELAY = 0.15             # Refresh speed

# Data Storage
current_spiral_coords = []
current_price = BASE_PRICE
spin_phase = 0.0

print("Generating the 3-Minute Life Cycle Tornado...")
print("Phase 1: 2-Minute Consolidation | Phase 2: 1-Minute Liquidation Drop")
time.sleep(1.5)

for step in range(1, TOTAL_STEPS + 1):
    spin_phase += 0.4
    
    # 1. PHASE CONTROL (Simulating your exact market script)
    if step <= CONSOLIDATION_STEPS:
        # First 2 Minutes: Stay tight in a $0.50 grinding range
        price_change = np.random.choice([-0.10, -0.05, 0.0, 0.05, 0.10])
        current_price += price_change
        # Keep it bound strictly within +/- $0.25 of BASE_PRICE
        current_price = max(BASE_PRICE - 0.25, min(current_price, BASE_PRICE + 0.25))
        
        # Standard ranging delta volume
        delta = np.random.uniform(-1.0, 1.0)
    else:
        # Last 1 Minute: Price drops hard by $2.00 total across 30 steps
        current_price -= (2.00 / DROP_STEPS)
        
        # Heavy selling delta dominates the fast drop
        delta = np.random.uniform(-1.5, -0.2)
        
    current_price = round(current_price, 3)

    # 2. THE 0.25 PROPORTIONAL OVAL PHYSICS ENGINE
    # The absolute maximum width allowed is 25% of our vertical price grid space
    max_allowed_width = PRICE_RANGE_SPAN * WIDTH_RATIO # 6.0 * 0.25 = 1.5 units
    
    y_radius = max_allowed_width * 0.35  # Constant depth baseline
    # Delta stretches the oval horizontally up to our strict 0.25 threshold boundary
    x_radius = y_radius + (abs(delta) * (max_allowed_width - y_radius))
    x_radius = max(0.2, min(x_radius, max_allowed_width))

    # 3. WEAVE THE CONTINUOUS SPIRAL LAYER
    theta = np.linspace(0, 2 * np.pi, 25)
    x_ring = x_radius * np.cos(theta + spin_phase)
    y_ring = y_radius * np.sin(theta + spin_phase)
    z_price = np.full_like(theta, current_price)

    # Color mapping logic based on Delta changes during the drop vs consolidation
    if step > CONSOLIDATION_STEPS:
        # Liquidation colors: Deep metallic crimson/orange wire
        color_hex = '#d35400' if delta > -0.8 else '#c0392b'
    else:
        # Consolidation colors: Balanced market steel blue
        color_hex = '#34495e' if delta < 0 else '#7f8c8d'

    # Append points into the unbroken thread sequence
    for i in range(len(theta)):
        current_spiral_coords.append({
            'x': x_ring[i],
            'y': y_ring[i],
            'price': z_price[i],
            'color': color_hex,
            'is_latest_ring': (step == TOTAL_STEPS) # Tag the very last ring
        })

    # 4. BUILD THE 3D SCENE
    fig = go.Figure()

    # Draw the central base price tube axis (The zero-core backbone)
    fig.add_trace(go.Scatter3d(
        x=[0, 0], y=[0, 0], z=[BASE_PRICE - 3, BASE_PRICE + 3],
        mode='lines',
        line=dict(color='rgba(255, 255, 255, 0.15)', width=4, dash='dash'),
        name="Center Core"
    ))

    # Segment the single continuous thread into blocks to allow multi-color mapping
    # Loop through and draw the accumulating wire sculpture
    points_per_ring = 25
    for r in range(step):
        start_idx = r * points_per_ring
        end_idx = start_idx + points_per_ring
        ring_data = current_spiral_coords[start_idx:end_idx]
        
        if not ring_data: continue
        
        # Condition: If it's the absolute final tick of the 3-minute life, make it Aqua Neon
        if step == TOTAL_STEPS and r == (step - 1):
            line_color = '#00fdfd' # Flawless Aqua Neon
            line_width = 8         # Extra glowing thickness
        else:
            line_color = ring_data[0]['color']
            line_width = 3

        fig.add_trace(go.Scatter3d(
            x=[p['x'] for p in ring_data],
            y=[p['y'] for p in ring_data],
            z=[p['price'] for p in ring_data],
            mode='lines',
            line=dict(color=line_color, width=line_width),
            hoverinfo='none',
            showlegend=False
        ))

    # 5. FIXED PROPORTIONAL VIEWPORT
    fig.update_layout(
        template="plotly_dark",
        title=f"🌪️ 3-Min Lifecycle Tornado (Scale Width: {WIDTH_RATIO}x | Active Price: ${current_price:.2f})",
        scene=dict(
            xaxis=dict(title='Delta Width', range=[-max_allowed_width - 0.5, max_allowed_width + 0.5]),
            yaxis=dict(title='Volume Depth', range=[-max_allowed_width - 0.5, max_allowed_width + 0.5]),
            zaxis=dict(title='Price Level ($)', range=[BASE_PRICE - 3.5, BASE_PRICE + 1.5]),
            camera=dict(eye=dict(x=1.4, y=-1.4, z=0.6)) # Flat side profile angle to clearly watch the drop
        ),
        height=750,
        margin=dict(l=0, r=0, b=0, t=40)
    )

    # 6. Push frame to screen
    clear_output(wait=True)
    fig.show()
    time.sleep(FRAME_DELAY)