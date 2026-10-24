<div align="center">

# 🌬️ The Solder Fume Extractor
### *A quiet, repairable fume extractor for the solder bench — built to last, not to be replaced*

<img src="https://RolandThsive.github.io/FeaturedImages/3855833578594226507.jpg" alt="The Solder Fume Extractor" width="720"/>

[![Blog](https://img.shields.io/badge/Build%20Guide-ro--h--bots-FF5722?style=for-the-badge&logo=blogger&logoColor=white)](https://ro-h-bots.blogspot.com/2026/06/solder-fume-extractor.html)
[![YouTube](https://img.shields.io/badge/See%20it%20run-YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/watch?v=w06uP-Srhxs)
[![Instagram](https://img.shields.io/badge/@ro__h__bots-Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/ro_h_bots)

![ESP32](https://img.shields.io/badge/MCU-ESP32-E7352C?style=flat-square&logo=espressif&logoColor=white)
![Arduino](https://img.shields.io/badge/Firmware-Arduino-00878F?style=flat-square&logo=arduino&logoColor=white)
![Blender](https://img.shields.io/badge/CAD-Blender-F5792A?style=flat-square&logo=blender&logoColor=white)
[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg?style=flat-square)](http://creativecommons.org/licenses/by-nc-sa/4.0/)

</div>

---

## ✨ Overview

A desktop fume extractor designed for my own solder table, because the commercial ones all seemed to be built with planned obsolescence in mind.

An **Arctic P14 Pro** PWM fan pulls fumes through a **carbon filter**. Fan speed is set with a **multi-turn precision potentiometer**, read by an **ESP32** that drives the fan at a silent **25 kHz PWM**. The filter cover is **magnetic** and snaps into place, so swapping the filter takes a few seconds and no tools.

---

## 🔧 Features

- 🧲 **Tool-free filter swaps** — the magnetic cover snaps on and off in seconds
- 🎛️ **Fine speed control** with a multi-turn precision pot
- 🔇 **25 kHz PWM** — above human hearing, so no fan whine; never drops below 5 % duty
- 🛡️ **Custom grills on both sides** of the fan keep fingers and filter material out of the blades
- 🧱 **One-piece main body** with embedded nuts and magnets
- 🪛 Metal washers on the sides protect the plastic where the stand clamps on

---

## 📸 Gallery

<div align="center">

| Fume Extractor Assembly | Stand Assembly — Concept 1 |
| :---: | :---: |
| <img src="CAD/GLTFs/Full%20Assembly/Model%20Viewer%20-%20SolderFumeExtractor_FullAssembly/SolderFumeExtractor_FullAssembly_Compressed.png" width="300"/> | <img src="CAD/GLTFs/SFE_Stand_Concept1/Model%20Viewer%20-%20SFE_Stand_Concept1/SFE_Stand_Concep1.png" width="300"/> |

*Want to spin these around? The blog post has interactive 3D viewers for each of them.*

</div>

---

## 📖 Instructions

For the full write-up, interactive 3D models and a video of the real thing, head to the official blog post:
👉 [The Solder Fume Extractor Guide](https://ro-h-bots.blogspot.com/2026/06/solder-fume-extractor.html)

> [!NOTE]
> The stand is still a work in progress. Concept 1 is in the repo; Concept 2 — simpler and less intrusive — is on the way.

---

## 🛠️ Bill of Materials (BOM)

| Quantity | Item Description |
| :---: | :--- |
| **1x** | Arctic P14 Pro PWM fan |
| **1x** | Carbon filter |
| **1x** | ESP32 development board |
| **1x** | Multi-turn precision potentiometer *(Bourns 3590S-2-102L, 1 kΩ)* + printed knob |
| **1x** | Power switch |
| **1x** | DC barrel jack, 5.5 x 2.5 mm |
| **—** | M3 x 8 mm and M3 x 10 mm Allen bolts |
| **—** | M3 nuts *(embedded during printing)* |
| **—** | 4 x 4 mm and 4 x 1.5 mm neodymium magnets |
| **2x** | M8 washers *(super-glued to the sides for the stand)* |
| **1x** | Set of 3D printed parts *(Found in the `CAD/Solder Fume Extractor CAD/STLs` folder)* |

> Exact screw, nut and magnet counts can be read off the STEP files in `CAD/Solder Fume Extractor CAD/Steps/`.

---

## ⚡ Wiring & Firmware

The insides are deliberately simple: fan, pot and switch wired to the ESP32.

| Signal | ESP32 Pin | Notes |
| :--- | :---: | :--- |
| Fan PWM | `GPIO 7` | 25 kHz, 8-bit resolution |
| Potentiometer wiper | `GPIO 2` | 12-bit ADC, 11 dB attenuation |

The sketch lives in [`Program/Solder_fume_extrator_speedController/`](Program/Solder_fume_extrator_speedController). It maps the pot reading to a fan duty cycle between **5 % and 100 %**, updating every 100 ms.

> [!IMPORTANT]
> The sketch uses the `ledcAttach()` API, so it needs **Arduino-ESP32 core 3.x** or newer.

---

## 📁 Repository Structure

```
Solder-Fume-Extractor/
├── CAD/
│   ├── Solder Fume Extractor CAD/
│   │   ├── STLs/                # Files to print
│   │   ├── Steps/               # STEP assemblies + unique parts
│   │   └── Prts/                # Native part files
│   ├── Blender Project/         # Full assembly, exploded view, stand concept
│   ├── GLTFs/                   # Web-ready 3D models + model-viewer pages
│   └── Arctic Fans CAD/         # Fan reference models
├── Documentations/              # Potentiometer datasheet, DC jack drawings
├── Program/
│   └── Solder_fume_extrator_speedController/   # Arduino sketch
├── LICENSE.txt
└── README.md
```

---

## 🌐 Connect With Me
* **Blog:** [ro-h-bots.blogspot.com](https://ro-h-bots.blogspot.com/)
* **Insta:** [@ro_h_bots](https://www.instagram.com/ro_h_bots?igsh=cDNkcnNpYnB5aWR1)

---

## License

[![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg

<div align="center">

Made with love by **RolandThsive ([@RolandThsive](https://github.com/RolandThsive))**

</div>
