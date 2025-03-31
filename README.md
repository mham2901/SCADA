# 💧 Smart Industrial Water Treatment SCADA System

This project is a complete, real-time **SCADA system** for monitoring and controlling an **industrial water treatment process**, developed using:

- 🧠 **CoDeSys** for PLC logic (ABB PM5072)
- 🌐 **Ignition SCADA** for UI, control, charting, and alarms
- 🗄️ **SQLite** for manual data logging
- 💻 **CP607 HMI** and OPC UA / Modbus TCP for communication

---

## 🚀 Project Features

### ✔️ Multi-Stage Process
- **Water Intake & Filtration**
- **pH Monitoring & Calibration**
- **Chemical Balancing**
- **Water Level Monitoring**
- **Quality Testing & Discharge**

### 🛠️ SCADA Functionalities
- **Real-time Dashboard**
- **Historical Trends with Easy Chart**
- **SQLite Data Logging**
- **Blinking Alarms with ST Logic**
- **Maintenance & Manual Control Panel**
- **Multi-window Navigation (Overview, Trends, Alarms, Maintenance)**

### 🔁 Communication
- Ignition ↔️ ABB PM5072 PLC via **OPC UA / Modbus TCP**
- PLC logic coded in **Structured Text (ST)** & **Ladder Logic (LD)**

---

## 🧪 Technical Stack

| Layer          | Tech Used                    |
|----------------|------------------------------|
| PLC            | ABB PM5072 + CoDeSys         |
| SCADA          | Ignition 8.1 (Vision module) |
| Database       | SQLite (Techxpert connection)|
| Comm Protocols | OPC UA, Modbus TCP           |
| Language       | ST (IEC 61131-3), Jython     |

---

## ⚙️ Project Structure

```plaintext
📁 /PLC
 └─ Program Files (.project, .library)
📁 /Ignition
 └─ Vision Windows (.vwin), Scripts, Tag Export
📁 /Database
 └─ SQLite Schema + Example Inserts
📁 /Docs
 └─ Functional Overview, Ladder Charts
README.md
