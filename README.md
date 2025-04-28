# SA-MP Drug Production System 🌿

A full-featured drug manufacturing system for SA-MP RPG servers, written in Pawn.  
Designed for gang and mafia factions, this system allows players to create drugs through an interactive and progressive process.

## 🎮 What Is This?

This system enables faction players (gangs, mafias) to manufacture drugs within the game world.  
It includes crafting mechanics, resource management, time-based production, and control features for balancing gameplay.

A special Developer Mode is included to assist with testing and debugging during development.

## 🧩 Features

- Drug production system for RPG servers
- Crafting process with resource and timing logic
- Restricted to specific factions (gangs, mafias)
- Anti-abuse and security checks
- Developer Mode for fast testing and debugging
- Hook-based integration with server events
- Clean modular structure for easy expansion

## 🗂 File Structure

- `main.inc` – Entry point connecting all modules
- `functions.inc` – Core production logic (start, progress, complete crafting)
- `static_functions.inc` – Helper utilities (timing, formatting, validation)
- `hooks.inc` – Integration with events (player actions, server hooks)
- `vars.inc` – Public variables (player states, timers, etc.)
- `static_vars.inc` – Internal static configuration
- `developer_mode.inc` – Testing and debugging tools for developers

## 🧱 Technologies Used

- **Pawn** – Main scripting language
- **SA-MP 0.3.7** – Multiplayer framework
- Designed to be easily extendable to MySQL or admin panels

## 🚀 How to Use

1. Copy all `.inc` files into your `includes/` directory.
2. In your gamemode or filterscript:
   ```pawn
   #include "main"
3.    Hook into player commands and events for proper system operation.
4.    Grant developer access only to trusted administrators for debugging.

👨‍💻 Author

Developed by Tigran Kocharov
📧 tiko.nue@icloud.com

📄 License & Attribution

This project was originally created for a private SA-MP RPG server.
It is now shared publicly for educational and non-commercial use.
If you use or modify this project, proper attribution is required.

