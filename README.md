# esp32-security-pir-buzzer
A security system with armed and disarmed feature to buzzer when motion is detected

🔧 Objective
Create a basic security system using an ESP32 that:

Toggles between Armed and Disarmed modes using a push button

Detects motion via a PIR sensor

Triggers an active buzzer when motion is detected while armed

Optionally displays system status on an OLED screen

Components Used:
| Component              | Quantity     | Notes                     |
| ---------------------- | ------------ | ------------------------- |
| ESP32 Dev Board        | 1            |                           |
| PIR Sensor             | 1            | For motion detection      |
| Push Button            | 1            | Used to toggle arm/disarm |
| Buzzer (Active)        | 1            | For alarm sound           |
| OLED Display (SSD1306) | 1 (optional) | I2C, 128x64               |
| Jumper Wires           | –            |                           |
| Breadboard             | 1            | Optional for prototyping  |

Pin connections:
| Component | ESP32 GPIO Pin | Notes                 |
| --------- | -------------- | --------------------- |
| PIR OUT   | GPIO 14        | Motion signal         |
| Button    | GPIO 13        | Uses internal pull-up |
| Buzzer +  | GPIO 26        | Alarm output          |
| OLED SDA  | GPIO 21        | I2C Data              |
| OLED SCL  | GPIO 22        | I2C Clock             |


🧠 System Logic
Startup:

System initializes in Disarmed mode
OLED (if connected) displays “Disarmed”

Button Press:

On press + release, toggles isArmed
OLED and Serial output updated accordingly

When Armed:

If PIR sensor detects motion (HIGH signal)
Buzzer sounds continuously
OLED shows "Motion!"

When Disarmed:

Motion detection is ignored
Buzzer remains silent

🧪 Testing Steps
Upload the code to the ESP32
Power on the board

Observe:

System starts disarmed
Press button once ➝ System arms
Wave in front of PIR ➝ Buzzer sounds
Press button again ➝ System disarms
Buzzer stops even if motion is present

📈 Possible Upgrades:

Use a keypad to arm/disarm with a password
Send notifications via Wi-Fi (email/Telegram/etc.)
Add a web dashboard to monitor status remotely
Replace the buzzer with a relay + siren/light
Integrate battery backup for power loss protection
