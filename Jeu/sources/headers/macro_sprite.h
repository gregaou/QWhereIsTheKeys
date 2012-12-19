/**
 * \file			collision_oj_mechant_simple.h
 * \brief			Macro facilitant la création d'objet jeu lors de l'ajout d'un niveau
 * \author    GALLO Jean-Bernard
 * \version   1.0
 * \date      17/12/2012
 */

#ifndef MACRO_SPRITE_H
#define MACRO_SPRITE_H

/* -- OBJET MONSTRE SIMPLE -- */

/* Spider */
#define SPIDER(x,y,z) (new OjMechantSimple(x,y,":/spider/s_l1.png",":/spider/s_l2.png",":/spider/s_r1.png",":/spider/s_r2.png",z))

/* Garde */
#define GARDE(x,y,z) (new OjMechantSimple(x,y,":/garde/g_l1.png",":/garde/g_l2.png",":/garde/g_r1.png",":/garde/g_r2.png",z))

/* -- OBJET MONSTRE ROTATIF -- */

/* Spider */
#define SPIDERRED_U_1 QString(":/spiderred/sr_u1.png")
#define SPIDERRED_U_2 QString(":/spiderred/sr_u2.png")
#define SPIDERRED_D_1 QString(":/spiderred/sr_d1.png")
#define SPIDERRED_D_2 QString(":/spiderred/sr_d2.png")
#define SPIDERRED_L_1 QString(":/spiderred/sr_l1.png")
#define SPIDERRED_L_2 QString(":/spiderred/sr_l2.png")
#define SPIDERRED_R_1 QString(":/spiderred/sr_r1.png")
#define SPIDERRED_R_2 QString(":/spiderred/sr_r2.png")
#define SPIDERRED(x,y,z) (new OjMechantTourne(x,y,SPIDERRED_U_1,SPIDERRED_U_2,SPIDERRED_D_1,SPIDERRED_D_2,SPIDERRED_L_1,SPIDERRED_L_2,SPIDERRED_R_1,SPIDERRED_R_2,z))

/* -- OBJET FIX ANIME -- */

/*Lave*/
#define LAVE(x,y) (new OjFixAnime(x,y,":/flamme/lave1.png",":/flamme/lave2.png",":/flamme/lave3.png",":/flamme/lave4.png"))




#endif // MACRO_SPRITE_H
