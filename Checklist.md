Bomberman — Checklist
28 Sept 2026 · @Robin
0. Terminar el renombrado y compilar
El nombre del .exe sale del nombre del .vcxproj, así que al renombrarlo pasará a llamarse Bomberman.exe.
[ ] Cerrar Visual Studio y borrar .vs/, Debug/, Release/ y Bomberman/Debug/ y Bomberman/Release/ (guardan rutas y nombres viejos)
[ ] Renombrar los tres ficheros: Bomberman.vcxproj, Bomberman.vcxproj.filters, Bomberman.vcxproj.user
[ ] Abrir Bomberman.sln con el Bloc de notas y cambiar la línea 6: = "Bomberman", "Bomberman\Bomberman.vcxproj" (el GUID se deja igual)
[ ] En Bomberman.vcxproj cambiar <RootNamespace>My01window</RootNamespace> por Bomberman (opcional, solo estético)
[ ] Comprobar que la carpeta libs sigue a ..\..\..\libs del .vcxproj (GLEW 1.13, GLFW 3.3.8, glm, SOIL); si no, corregir rutas en Propiedades → C/C++ y Vinculador
[ ] Copiar glew32.dll (y freetype6.dll) junto al nuevo .exe en Debug/ y Release/
[ ] Compilar en Debug y en Release (Win32) y ver que arranca la demo de Bub igual que antes
[ ] Crear repositorio git con un .gitignore para .vs/, Debug/, Release/, *.user
1. Base del motor
Todo lo demás se apoya en esto, así que conviene hacerlo antes que las entidades.
[ ] Elegir tamaño de tile (p. ej. 16×16 escalado ×2) y resolución de ventana (SCREEN_WIDTH/SCREEN_HEIGHT)
[ ] Conseguir los sprites: tileset, Bomberman, enemigos, boss, bomba, explosión, items, puerta, HUD
[ ] Game: enum de estados MENU, PLAYING, INSTRUCTIONS, CREDITS (y quizá GAME_OVER, WIN) que decide qué pantalla se actualiza y pinta
[ ] Game: detectar pulsación única (tecla recién pulsada) además de getKey, para bombas, menús, G, K y 1–5
[ ] Scene::init(int level) que carga levels/level0X.txt y libera el nivel anterior
[ ] Formato de nivel: añadir posiciones de jugador, puerta, enemigos, bloques destructibles y tiempo límite
[ ] TileMap: collisionMoveUp para el techo al saltar
[ ] TileMap: getTile/setTile y reconstruir el VBO al romper un bloque (o pintar destructibles como sprites aparte)
[ ] TileMap: marcar qué tiles son sólidos, cuáles destructibles y cuáles decorativos
[ ] Colisiones caja-caja (AABB) genéricas entre entidades
[ ] Pintar texto (freetype o una fuente en sprite sheet) para menús y HUD
[ ] Cámara con scroll si los niveles son más grandes que la pantalla
2. Parte básica (6 puntos)
Sin esto la nota es un cero: el juego tiene que tener objetivo y volver a empezar al ganar o perder.
Pantallas
[ ] Menú principal (Jugar, Instrucciones, Créditos, Salir)
[ ] Pantalla de instrucciones
[ ] Pantalla de créditos
[ ] Pantalla de juego
[ ] Al perder las 3 vidas, volver al menú
[ ] Al pasar el nivel 5, pantalla de victoria y vuelta al menú
Bomberman
[ ] Moverse a izquierda y derecha, con gravedad
[ ] Saltar (reutilizar el salto de Bub, ajustando altura)
[ ] Animaciones: quieto, andar, saltar, muerte
[ ] 3 vidas; al morir, reaparecer en el inicio del nivel
[ ] Corazón: si lo tiene, un golpe no le quita vida
Bombas
[ ] Soltar bomba alineada al centro del tile más cercano
[ ] La bomba no cae: se queda flotando donde se suelta
[ ] Bomberman puede pararse encima de sus bombas y usarlas de escalera
[ ] Al salir de la bomba recién puesta no bloquea al jugador (solo es sólida cuando ya no la toca)
[ ] Límite de bombas simultáneas (maxBombs)
[ ] Temporizador y explosión en cruz con alcance firePower
[ ] La explosión se detiene en bloques sólidos y rompe el primer destructible que toca
[ ] La explosión mata enemigos y al propio Bomberman
[ ] Una explosión que toca otra bomba la hace explotar (reacción en cadena)
Mapa y objetos
[ ] Tiles destructibles (arbustos) que desaparecen con la explosión
[ ] Al romperse pueden soltar un objeto
[ ] Bomb Up (+1 bomba simultánea)
[ ] Fire Up (+1 alcance de explosión)
[ ] Corazón (aguanta un golpe)
[ ] Un cuarto objeto (p. ej. vida extra, reloj +tiempo, velocidad)
[ ] Puerta de salida que solo se abre al eliminar todos los enemigos
Enemigos
[ ] Clase base Enemy (posición, sprite, vida, colisión con el jugador)
[ ] Enemigo 1: patrulla de lado a lado y gira en paredes o bordes
[ ] Enemigo 2: comportamiento distinto (p. ej. salta o persigue al jugador)
[ ] Enemigo 3: comportamiento distinto (p. ej. vuela ignorando la gravedad)
[ ] Tocar un enemigo quita una vida
Niveles
[ ] Nivel 1
[ ] Nivel 2
[ ] Nivel 3
[ ] Nivel 4
[ ] Nivel 5 con boss (vida, patrón de ataque, animación de daño)
[ ] Tiempo límite por nivel; al acabarse, se pierde una vida
HUD
[ ] Tiempo restante
[ ] Vidas
[ ] Enemigos restantes
[ ] Bombas simultáneas
[ ] Alcance de la explosión
Teclas de depuración
[ ] G: activar o desactivar god mode (y mostrarlo en el HUD)
[ ] K: eliminar todos los enemigos y abrir la puerta
[ ] 1–5: cargar ese nivel directamente
3. Polish (4 puntos)
Sonido
[ ] Integrar librería de audio (irrKlang u otra que acepte el profe)
[ ] Música de menú, de nivel y de boss
[ ] Efectos: poner bomba, explosión, salto, recoger objeto, muerte, enemigo muerto, puerta abierta, victoria, game over
Animaciones y transiciones
[ ] Animación de explosión (centro, brazos y puntas) y de bloque rompiéndose
[ ] Muerte de Bomberman y de enemigos animada, no desaparición instantánea
[ ] Parpadeo de invulnerabilidad al perder vida o con corazón
[ ] Bomba que late antes de explotar
[ ] Puerta que se abre visiblemente
[ ] Fundido entre pantallas y al cambiar de nivel ("Stage X")
Game feeling
[ ] Ajustar velocidad, altura de salto y tiempos de bomba comparándolos con el juego original en emulador
[ ] Aviso de poco tiempo (HUD en rojo o música más rápida)
[ ] Probar todos los niveles de principio a fin buscando bugs (cada bug resta nota)
4. Entrega
Un zip llamado NomCognoms.zip de máximo 200 MB.
[ ] info.txt: nombres de los dos integrantes, funcionalidades hechas e instrucciones del juego
[ ] Carpeta Binari/: Bomberman.exe en Release + dlls + images/, levels/, shaders/, sounds/
[ ] Probar Binari/ en otro ordenador (o en otra carpeta) para confirmar que no falta nada
[ ] Carpeta Projecte/: código que compile, sin .vs/, Debug/ ni Release/
[ ] demo.avi de 1 minuto que enseñe todo, de menos de 100 MB (grabar con OBS, comprimir con HandBrake)