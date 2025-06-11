https://github.com/user-attachments/assets/65e665cf-b338-4950-9fd4-dc3476cf4918
<h1 align="center">🎮 LAB EXERCISE 5 - SECV2213 FUNDAMENTALS OF COMPUTER GRAPHICS</h1>
<h3 align="center">🧊 3D Textured Cube with Interaction & Sound</h3>

<p align="center">Welcome to my interactive OpenGL project — a 3D textured cube enhanced with user interaction, animation, and background music! 🎶✨</p>

This lab exercise showcases a blend of key concepts in computer graphics including:
- 🎨 *Texture mapping*
- 🕹️ *Keyboard and mouse interaction*
- 🔁 *3D transformations & animation*
- 🔊 *Sound integration*

---

## 🧱 Features

### 🔹 Textured Cube Rendering
- Each face of the cube is mapped with a *different BMP texture*.
- Textures are loaded using `glTexImage2D()` and a custom loader function.

### 🔹 Keyboard-Controlled Rotation
- Press *`x`* to toggle rotation on the X-axis.
- Press *`y`* to toggle rotation on the Y-axis.
- Uses `glutTimerFunc()` for smooth continuous rotation.

### 🔹 On-Screen Instructions
- Helpful text rendered using `renderBitmap()` with *bitmap fonts*.
- Text overlays use **orthographic projection**, so they don't interfere with the 3D cube view.

### 🔹 Background Music Integration
- Click the *left mouse button* to *toggle sound on/off*.
- Plays the *"Conan Detective" theme* using `PlaySound()` from the *Windows API*.
- Adds a fun, dynamic feel to the program 🎵

