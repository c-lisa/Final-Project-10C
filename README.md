LITTLE HIPPO THE PILOT

AUTHOR Written by Lisa Chiang (clisa928@g.ucla.edu)

BACKGROUND This project was created to fulfill the final project requirement of the PIC10C course at UCLA. It was inspired by a childhood imaginary game that my younger brother and I used to play that centered around a stuffed animal named Little Hippo who was a pilot. He saved his fellow animal friends from the "bad guys." 

SYNOPSIS This one-player game consists of the player taking the role of the protagonist, Little Hippo. The player moves left and right using the arrow keys and shoots using the spacebar. The player begins with three lives. As the game progresses and the player accumulates more points, the difficulty of the game gradually increases. The game continues until the player has 0 lives left. 

The game is coded in C++ in Qt. The .pro files, .h files, .cpp files, .jpg, .mp3, .qrc files, .png files are all included in the repository. 

RELEVANCE TO THE COURSE: 

Lambda Functions Example: 

   auto_inc_enemy_speed = [](int val){
      if(val>=25 && val&25 == 0) return true;
      else return false; 
   };

Memory Management Example: 

   if (typeid(*(colliding_items[i]))== typeid(Enemy)

   {   
   
      //other code
      scene() -> removeItem(colliding_items[i]); //not just removing item from scene
      scene() -> removeItem(this);
      deleting colliding_items[i]; //need to manage memory as well so bullet does not exist forever despite being off-screen
      delete this;
      return; 
   }
   
Qt Connections Example: 

   {
      
      //create timer for bullet to run
      QTimer * timer = new QTimer();
      connect(timer, SIGNAL(timeout()), this, SLOT(move())); //Using signal and slot, move() is defined function
      timer-> start(50);
   }

CREDIT

Background Image - SushiHighRoller (DeviantArt)

All other Images - drawn by me (Lisa Chiang)

Ricochet bullet mp3 - SoundBible

Background Music mp3 - SoundBible
