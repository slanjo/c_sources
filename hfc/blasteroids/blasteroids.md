### Blasteroids

----
----
### *Compotnents provided by Allegro*
1. GUI - Allegro will draw game window
2. Transoformation - Allegro will draw and manipulate objects on screen
3. Timer - Allegro will provide game heartbeat
4. Events - Allegro will handle the inputs from keyboard, mouse
5. Graphics Buffering - Allegro will draw a frame in an offscreen buffer beforr
6. Sounds - Allegro will provide sounds. 

###GUI

  * To draw a window this is used:

----
### *compiler & make * 
  *  ** blasteroids.c -I/usr/local/include/allegro5/* /usr/local/lib/liballegro* -o blasteroids** 
  *  <some text> 
  *  ** gcc hello.c -o hello $(pkg-config allegro-5 allegro_font-5 --libs --cflags)
  ``` Some code

  ``` 

---- 
### *Game Loop*
  * a vast majority of games implements a game loop. Game loop loops continously and does the following:  
  1. accept input from a player
  2. advance the game's variables by a single frame
  3. Render the code graphics according to variables

