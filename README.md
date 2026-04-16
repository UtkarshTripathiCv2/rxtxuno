🔹 🧰 COMPONENTS
2 × Arduino (UNO/Nano)
WS-TX02 (Transmitter)
WS-RX02 (Receiver)
1 × Push Button
1 × LED
1 × 220Ω Resistor
Wires
🔹 📤 TRANSMITTER SIDE (Arduino 1)
🔌 Connections
WS-TX02
VCC → 5V
GND → GND
DATA → D12

👉 (ignore extra VCC/GND if present)

Push Button
One leg → D2
Other leg → GND

👉 No resistor needed (we use INPUT_PULLUP)

🔹 Diagram (Simple)
[Button]
   |------ D2 (Arduino)
   |------ GND

[WS-TX02]
   VCC  → 5V
   GND  → GND
   DATA → D12
🔹 📥 RECEIVER SIDE (Arduino 2)
🔌 Connections
WS-RX02
VCC → 5V
GND → GND
DATA (any one) → D11

👉 Only use ONE DATA pin (others are duplicate)

LED
Anode (+ long leg) → D3
Cathode (short leg) → 220Ω resistor → GND
🔹 Diagram (Simple)
[WS-RX02]
   VCC  → 5V
   GND  → GND
   DATA → D11

[LED]
   D3 → LED (+)
   LED (-) → Resistor → GND
