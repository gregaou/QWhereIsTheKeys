#ifndef MACRO_SPRITE_H
#define MACRO_SPRITE_H

/* -- OBJET MONSTRE SIMPLE -- */

/* Spider */
#define SPIDER(x,y,z) (new OjMechantSimple(x,y,":/spider/s_l1.png",":/spider/s_l2.png",":/spider/s_r1.png",":/spider/s_r2.png",z))

/* Garde */
#define GARDE(x,y,z) (new OjMechantSimple(x,y,":/garde/g_l1.png",":/garde/g_l2.png",":/garde/g_r1.png",":/garde/g_r2.png",z))


/* -- OBJET FIX ANIME -- */

/*Lave*/
#define LAVE(x,y) (new OjFixAnime(x,y,":/flamme/lave1.png",":/flamme/lave2.png",":/flamme/lave3.png",":/flamme/lave4.png"))


#endif // MACRO_SPRITE_H
