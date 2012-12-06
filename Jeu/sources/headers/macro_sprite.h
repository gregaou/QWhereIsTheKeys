#ifndef MACRO_SPRITE_H
#define MACRO_SPRITE_H

/* -- OBJET MONSTRE SIMPLE -- */

/* Spider */
#define SPIDER_L_1 QString(":/spider/s_l1.png")
#define SPIDER_L_2 QString(":/spider/s_l2.png")
#define SPIDER_R_1 QString(":/spider/s_r1.png")
#define SPIDER_R_2 QString(":/spider/s_r2.png")
#define SPIDER(x,y,z) (new OjMechantSimple(x,y,SPIDER_L_1,SPIDER_L_2,SPIDER_R_1,SPIDER_R_2,z))

/* Garde */
#define GARDE_L_1 QString(":/garde/g_l1.png")
#define GARDE_L_2 QString(":/garde/g_l2.png")
#define GARDE_R_1 QString(":/garde/g_r1.png")
#define GARDE_R_2 QString(":/garde/g_r2.png")
#define GARDE(x,y,z) (new OjMechantSimple(x,y,GARDE_L_1,GARDE_L_2,GARDE_R_1,GARDE_R_2,z))


/* -- OBJET FIX ANIME -- */

/*Lave*/
#define LAVE_1 QString(":/flamme/lave1.png")
#define LAVE_2 QString(":/flamme/lave2.png")
#define LAVE_3 QString(":/flamme/lave3.png")
#define LAVE_4 QString(":/flamme/lave4.png")
#define LAVE(x,y) (new OjFixAnime(x,y,LAVE_1,LAVE_2,LAVE_3,LAVE_4))


#endif // MACRO_SPRITE_H
