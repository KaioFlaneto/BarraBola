#ifndef BARRABOLA_H
#define BARRABOLA_H

typedef struct barrabola BarraBola;

BarraBola* bb_create();

void bb_delete(BarraBola* bb);

void bb_init();

void bb_set_target(BarraBola* bb, float target);

void bb_update(BarraBola* bb);


#endif