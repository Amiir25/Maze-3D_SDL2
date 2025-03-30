🎮 3D Maze Game  

## Introduction  
Welcome to **3D Maze Game**, a first-person maze exploration game built using **C, SDL2, and Raycasting**. Navigate through a labyrinth and find the exit!  

This project was developed as part of my Software Engineering Portfolio Project. It showcases fundamental raycasting techniques, player movement mechanics, and 2D-to-3D rendering using SDL2.  

Live Demo: [Play Here](#)  
Project Blog: [Read Here](#)  

---

## Screenshots
 
(textures/image-1.PNG)
(textures/image-2.PNG)

---

## Technologies Used

- C – Core programming language  
- SDL2 – Graphics rendering & input handling  
- SDL2_image – Loading textures  
- Raycasting Algorithm – Used to create the 3D illusion  

---

## Installation  

1️ Clone the Repository  
2️ Install Dependencies: Make sure SDL2 and SDL2_image are installed on your system.
3️ Build the Game
4️ Run the Game

---

## Controls

W / ↑ – Move Forward

S / ↓ – Move Backward

A / D – Strafe Left/Right

Left / Right Arrow – Rotate View

---

## Features
- 3D First-Person Exploration: Move through the maze with a realistic 3D perspective using raycasting.
- Textured Walls & Floor: The game supports custom textures, making the maze visually appealing.
- Customizable Maps: The game loads maps from a file, allowing users to design their own mazes.

---

## How It Works
- Raycasting
The game uses raycasting to simulate a 3D environment from a 2D grid. Each frame, rays are cast from the player's viewpoint, detecting walls and drawing scaled vertical slices to simulate depth.

---

## Core Algorithm Snippet
for (x = 0; x < SCREEN_WIDTH; x++)
{
    float rayAngle = (playerAngle - FOV / 2) + ((float)x / SCREEN_WIDTH) * FOV;
    float rayX = cos(rayAngle);
    float rayY = sin(rayAngle);
    
    while (!hitWall)
    {
        mapX = (int)(rayPosX / TILE_SIZE);
        mapY = (int)(rayPosY / TILE_SIZE);
        if (map[mapY][mapX] == 1) hitWall = true;
    }
    
    drawWallSlice(x, distance);
}

---

## Project Timeline & Development
Week 1: Research & planning (raycasting, SDL2 basics)

Week 2: Implemented raycasting & wall rendering

Week 3: Added textures & refined game logic

---

## Contributing
Want to improve this project? Follow these steps:
- Fork the repository
- Create a new branch
- Commit your changes
- Push to your branch
- Submit a Pull Request

## Related Projects
- Wolfenstein 3D – Inspiration for raycasting
- SDL2 Documentation – Official SDL documentation

---

##License
This project is licensed under the MIT License.

## Author
Developed by: Amir Sadik
- GitHub: https://github.com/Amiir25
- LinkedIn: https://www.linkedin.com/in/amir-sadik-355190287/
- Twitter: https://x.com/0x0A_mir
