# 🤖 SmartAssistant - Voice-Enabled Desktop Assistant

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20MacOS-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

A cross-platform voice-enabled assistant that can open applications, folders, and websites through voice/text commands.

## ✨ Features

- **Voice Interaction** (Text-to-Speech)
- **Cross-Platform Support** (Windows/Linux/Mac)
- **Quick Access to**:
  - Applications (Calculator, Notepad, Task Manager)
  - Folders (Pictures, Music, Downloads)
  - Websites (YouTube, Google Maps, Weather)
- **Custom Command Support**

## 📦 Installation

### Prerequisites
- C++17 compiler
- `espeak` for voice output (Linux/Mac: `sudo apt install espeak`, Windows: [Download](http://espeak.sourceforge.net))

### Build Instructions
```bash
git clone https://github.com/Meetbhesara/SmartAssistant.git
cd SmartAssistant
g++ -std=c++17 SmartAssistant.cpp -o SmartAssistant
