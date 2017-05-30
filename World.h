
#ifndef WORLD_H
#define WORLD_H
#include <stdint.h>
#include <stdbool.h>


typedef struct
{
	double x, y, direction;
}Position_s;

typedef struct
{
	double width, depth, height; //agregar toda la info necesaria de la forma
	Position_s Position;
}Robot_s;

typedef struct
{
	//informacion necesaria para el mapa
}Map_s;

int16_t W_Init(Map_s * mapInfo);   //set map
int16_t W_Update(void);  //avanzar la simulacion. devuelve codigo de error, o de si choco o no, o ambos
void W_setRobotConfiguration(Robot_s * _myRobot);


//Servicios

typedef struct sensData_t
{
	double angle;
	double distance;
};

sensData_t W_getSensorData(uint16_t sensorID);  //despues el sensor se fija que significa esto para este sensor
bool W_configureRobot(uint16_t _direction, uint16_t _velocity);

position_s W_getRobotPosition(void);


/*
static Robot_s myRobot;
static Map_s myMap;
*/

#endif //WORLD_H