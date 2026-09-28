# Bomberman 2D

Juego de plataformas en 2D basado en el *Pocket Bomberman* de Game Boy Color, hecho en C++ con OpenGL para la práctica **Exercici 2D** de VJ (Videojocs), curso 2026/27 Q1.

Bomberman tiene que eliminar a todos los enemigos de cada nivel y llegar a la puerta antes de que se acabe el tiempo. Sus bombas no caen: se quedan flotando donde las suelta, así que puede subirse encima y usarlas como escalera para llegar a zonas altas. En el quinto nivel le espera un boss.

## Autores

- Nombre Apellidos
- Nombre Apellidos

## Requisitos

- Windows con Visual Studio 2026 (toolset v145), configuración Win32
- Librerías en la carpeta `libs`, tres niveles por encima del `.vcxproj` (`..\..\..\libs`):
  - GLEW 1.13.0
  - GLFW 3.3.8
  - GLM
  - SOIL (Simple OpenGL Image Library)

## Compilar y ejecutar

1. Abrir `Bomberman.sln` en Visual Studio.
2. Elegir `Debug` o `Release` y la plataforma `Win32`.
3. Compilar con **Compilar → Compilar solución** (Ctrl+Mayús+B).
4. Ejecutar con F5. El directorio de trabajo es la carpeta del proyecto, donde están `images/`, `levels/`, `shaders/` y `sounds/`.

Para ejecutar el `.exe` fuera de Visual Studio, deja junto a él `glew32.dll`, `freetype6.dll` y las carpetas de recursos.

## Controles

| Tecla | Acción |
| --- | --- |
| ← → | Moverse |
| ↑ | Saltar |
| Espacio | Poner bomba |
| Enter | Aceptar en los menús |
| Esc | Volver al menú / salir |

### Teclas de depuración

| Tecla | Acción |
| --- | --- |
| G | Activar o desactivar el modo dios (invulnerable) |
| K | Eliminar todos los enemigos y abrir la puerta |
| 1 – 5 | Cargar ese nivel directamente |

## Objetos

| Objeto | Efecto |
| --- | --- |
| Bomb Up | +1 bomba simultánea |
| Fire Up | +1 casilla de alcance de la explosión |
| Corazón | Aguanta un golpe sin perder vida |
| *(por decidir)* | |

## Estructura del proyecto

```
Bomberman/
├── Bomberman.sln
└── Bomberman/
    ├── main.cpp, Game.*          Bucle principal y estados (menú, juego, instrucciones, créditos)
    ├── Scene.*                   Nivel en juego: entidades, colisiones, temporizador
    ├── Menu.*, Instructions.*, Credits.*
    ├── Player.*                  Movimiento, salto, bombas, vidas
    ├── Bomb.*, Explosion.*
    ├── Enemy.* (+ subclases), Boss.*
    ├── Item.*, Door.*
    ├── HUD.*, Text.*, SoundManager.*
    ├── TileMap.*, Sprite.*, Texture.*, Shader.*, ShaderProgram.*, AnimKeyframes.h
    ├── shaders/                  Shaders GLSL
    ├── levels/                   level01.txt … level05.txt
    ├── images/                   Tilesets y spritesheets
    └── sounds/                   Música y efectos
```

## Formato de los niveles

Cada `levels/levelXX.txt` empieza con la cabecera del `TileMap` de la plantilla de clase:

```
TILEMAP
36 28              -- Tamaño del mapa en tiles
16 32              -- Tamaño de tile y de bloque
images/tiles.png   -- Tilesheet
4 4                -- Tiles en el tilesheet (columnas filas)
<matriz del mapa>
```

*(Completar cuando esté decidido cómo se indican el inicio del jugador, la puerta, los enemigos, los bloques destructibles y el tiempo límite.)*

## Estado

Ver la checklist del proyecto. Resumen de la parte básica:

- [ ] Menú, instrucciones, créditos y juego
- [ ] Movimiento y salto
- [ ] Bombas alineadas a tiles, explosión y saltar sobre ellas
- [ ] Bloques destructibles y 4 objetos
- [ ] 3 enemigos distintos y boss
- [ ] 5 niveles con tiempo límite
- [ ] HUD
- [ ] Teclas G, K y 1–5

## Créditos

- Código base: plantilla `02-Bubble` de las prácticas de VJ (FIB–UPC).
- *Pocket Bomberman* © Hudson Soft / Konami. Sprites usados solo con fines educativos.
- Fuentes de sprites y sonidos: *(añadir enlaces)*
