# EarEEG — Demo App for Daily Focus Tracking  

**Project details**  
A lightweight **mobile demo application** that visualizes **focus level** in real time using simulated earEEG signals.  
The app is a prototype for future integration with real hardware.  


## Why this app?  
We chose to build this demo because **earEEG** technology allows convenient and mobile recording of brain activity.  
Unlike traditional EEG, it can be worn daily and unobtrusively, making it an excellent tool for studying focus during real-world tasks (e.g., reading, listening, working).  


## Content
- [How it works](./README.md#how-it-works)
- [App examples](./README.md#app-examples)
- [Current features](./README.md#current-features)
- [Roadmap](./README.md#roadmap)
- [How to run the app](./README.md#how-to-run-the-app)
  - [Environment](./README.md#environment)
  - [Used technologies](./README.md#used-technologies)
  - [Database and data](./README.md#database-and-data)
  - [Run the app](./README.md#run-the-app)
- [Contact](./README.md#contact)

## How it works  
In the current demo mode, the app uses a selected **EEG dataset** ([OpenNeuro ds004015](https://openneuro.org/datasets/ds004015/versions/1.0.2)) to simulate incoming brainwave data.  
These signals are processed (filtering, band power analysis, entropy measures), then passed through a lightweight **ML model** to estimate focus level.  

➡️ In the future, the dataset simulation will be replaced with **real-time input from earEEG hardware**.  

## App examples

## Current features  
The prototype already includes:  
- 📱 **User Interface (UI)** – visualization of focus level with simple charts and feedback  
- 🗄️ **SQLite integration** – automatic creation of required tables for storing data  
- ☁️ **Supabase-ready** – prepared for optional cloud synchronization in the future  
- ⚡ **Data Generator** – simulates earEEG input for testing without real hardware  
- 📦 **Batch handling** – infrastructure for chunked data processing  
- 🧠 **Biofeedback & recommendations** – app reacts to focus level and suggests micro-actions  

## Roadmap  
Next development steps:  
- 🔗 Connect with **real earEEG hardware**  
- 📊 Improve signal processing (FFT, band power analysis, entropy measures)  
- 🌐 Enable **secure cloud storage** of data (Supabase or other)  
- 📱 Extend the mobile UI with **recommendations & history view**  

## How to run the app

### Environment
- 🐧 **Linux** (tested on Linux Mint 21/22)  
- 📱 **SDK emulator** for mobile builds (Android)  
- 💻 Desktop build & run via **Qt Creator**  

### Used technologies 
- 🎨 **QML** – modern, declarative UI  
- 💻 **C++** – backend logic, data streams, signal processing  
- 🏗️ **CMake** – build system configuration  
- 🗄️ **SQLite** – lightweight local database for persistent storage  
- ☁️ **Supabase** – prepared for optional cloud synchronization  

### Database and data
- The app automatically **creates required SQLite tables** on first run (focus levels, raw data, session info).  
- Current demo mode uses **simulated data** (via generator or sample dataset) to fill the database.
- Planned extension: replace simulated/demo data with **real earEEG hardware input**, streamed and stored in the same database structure.  
- Database schema is designed to be **portable and extensible**, supporting both local storage and synchronization with **Supabase cloud**.  

### Run the app
Download files from GitHub and open project in Qt Creator
```
git clone https://github.com/humanplusplus/EarEEG_DemoApp
```

## Contact
If you are interested in collaboration, research, or supporting development, feel free to reach out ✉️ humannnplusplus[at]gmail.com
