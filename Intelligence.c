
#include "Intelligence.h"
#include "Senact.h"
#include <math.h>

#define SENSORS_AMMOUNT	12
#define INTELIGENCE_1	1
#define ANGLE_SECOND_SENSOR	0.6981317
#define DISTANCE_PJ	
#define MIN_DISTANCE  20


#define RIGHT_MOTOR 0
#define LEFT_MOTOR	1


#define IAN_RIGHT	-6

static startAuto1(void);
static startAuto2(void);
static startAssisted1(void);
static startAssisted2(void);
static startManual(void);

static int16_t inteligenceType;
static uint16_t mySensors[SENSORS_AMMOUNT];


///////////////////////////////////////////////////////////////////////////////
#define ANGLE_RANGES			12			//cantidad de rangos de angulos, de a 30 grados (ver de usar arreglo de estos ranges en vez de la estructura del .h)
#define ROBOT_WIDTH				15			//ver en cm o en que medida
#define ROBOT_LENGTH			15

#define SENSOR_0_POSITION_X		3
#define SENSOR_0_POSITION_Y		5
#define SENSOR_0_ANGLE			0

#define SENSOR_1_POSITION_X		4
#define SENSOR_1_POSITION_Y		10
#define SENSOR_1_ANGLE			45

#define SENSOR_2_POSITION_X		NULL
#define SENSOR_2_POSITION_Y		NULL
#define SENSOR_2_ANGLE			NULL

#define SENSOR_3_POSITION_X		NULL
#define SENSOR_3_POSITION_Y		NULL
#define SENSOR_3_ANGLE			NULL

#define SENSOR_4_POSITION_X		NULL
#define SENSOR_4_POSITION_Y		NULL
#define SENSOR_4_ANGLE			NULL

#define SENSOR_5_POSITION_X		NULL
#define SENSOR_5_POSITION_Y		NULL
#define SENSOR_5_ANGLE			NULL

#define SENSOR_6_POSITION_X		NULL
#define SENSOR_6_POSITION_Y		NULL
#define SENSOR_6_ANGLE			NULL

#define SENSOR_7_POSITION_X		NULL
#define SENSOR_7_POSITION_Y		NULL
#define SENSOR_7_ANGLE			NULL

#define SENSOR_8_POSITION_X		NULL
#define SENSOR_8_POSITION_Y		NULL
#define SENSOR_8_ANGLE			NULL

#define SENSOR_9_POSITION_X		NULL
#define SENSOR_9_POSITION_Y		NULL
#define SENSOR_9_ANGLE			NULL

#define SENSOR_10_POSITION_X	NULL
#define SENSOR_10_POSITION_Y	NULL
#define SENSOR_10_ANGLE			NULL

#define SENSOR_11_POSITION_X	NULL
#define SENSOR_11_POSITION_Y	NULL
#define SENSOR_11_ANGLE			NULL

enum {SENSOR_0, SENSOR_1, SENSOR_2, SENSOR_3, SENSOR_4, SENSOR_5, SENSOR_6, SENSOR_7, SENSOR_8, SENSOR_9, SENSOR_10, SENSOR_11}sensors;

//////////////////////////////////////////////////////
 
typedef struct
{
	int angle;
	int measuredDistance;
	int fromX;
	int fromY;
}sensorInfo_s;

typedef struct
{
	double x;
	double y;
}coordinate_s;

static sensorInfo_s allInfo[SENSORS_AMMOUNT];	//tiene que estar creado en algun lugar. NO GLOBAL
static coordinate_s allCoordinates[SENSORS_AMMOUNT];

//proptotipos
void initSensorsData(sensorInfo_s* allInfo);
void saveReferencedData(coordinate_s* allCoordinates, sensorInfo_s* allInfo);

//ejemplo de llamadas a las funciones
int main void
{
	initSensorsData(allInfo);
	saveReferencedData(allCoordinates,allInfo);
	return 0;
}


void initSensorsData(sensorInfo_s* allInfo)
{
	for (sensors i=0; i < SENSOR_AMMOUNT; i++)
	{
		switch (i)
		{
		case SENSOR_0:
		{
			allInfo[i].fromX = SENSOR_0_POSITION_X;
			allInfo[i].fromY = SENSOR_0_POSITION_Y;
			allInfo[i].angle = SENSOR_0_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_1:
		{
			allInfo[i].fromX = SENSOR_1_POSITION_X;
			allInfo[i].fromY = SENSOR_1_POSITION_Y;
			allInfo[i].angle = SENSOR_1_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_2:
		{
			allInfo[i].fromX = SENSOR_2_POSITION_X;
			allInfo[i].fromY = SENSOR_2_POSITION_Y;
			allInfo[i].angle = SENSOR_2_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_3:
		{
			allInfo[i].fromX = SENSOR_3_POSITION_X;
			allInfo[i].fromY = SENSOR_3_POSITION_Y;
			allInfo[i].angle = SENSOR_3_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_4:
		{
			allInfo[i].fromX = SENSOR_4_POSITION_X;
			allInfo[i].fromY = SENSOR_4_POSITION_Y;
			allInfo[i].angle = SENSOR_4_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_5:
		{
			allInfo[i].fromX = SENSOR_5_POSITION_X;
			allInfo[i].fromY = SENSOR_5_POSITION_Y;
			allInfo[i].angle = SENSOR_5_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_6:
		{
			allInfo[i].fromX = SENSOR_6_POSITION_X;
			allInfo[i].fromY = SENSOR_6_POSITION_Y;
			allInfo[i].angle = SENSOR_6_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_7:
		{
			allInfo[i].fromX = SENSOR_7_POSITION_X;
			allInfo[i].fromY = SENSOR_7_POSITION_Y;
			allInfo[i].angle = SENSOR_7_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_8:
		{
			allInfo[i].fromX = SENSOR_8_POSITION_X;
			allInfo[i].fromY = SENSOR_8_POSITION_Y;
			allInfo[i].angle = SENSOR_8_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_9:
		{
			allInfo[i].fromX = SENSOR_9_POSITION_X;
			allInfo[i].fromY = SENSOR_9_POSITION_Y;
			allInfo[i].angle = SENSOR_9_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_10:
		{
			allInfo[i].fromX = SENSOR_10_POSITION_X;
			allInfo[i].fromY = SENSOR_10_POSITION_Y;
			allInfo[i].angle = SENSOR_10_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		case SENSOR_11:
		{
			allInfo[i].fromX = SENSOR_11_POSITION_X;
			allInfo[i].fromY = SENSOR_11_POSITION_Y;
			allInfo[i].angle = SENSOR_11_ANGLE;
			allInfo[i].measuredDistance = NULL;
		}
		break;
		}
	}
}

void saveReferencedData(coordinate_s* allCoordinates,sensorInfo_s* allInfo)
{

}


/////////////////////////////////////////////////////////////////////////////
void I_Update(int16_t _intelligenceType)
{
	int i;
	for (i = 0; i <= SENSORS_AMMOUNT; i++)
		mySensors[i] = SA_getSensorState(i);
	switch (_intelligenceType) 
	{
	case AUTO1:
		startAuto1();
		break;
	case AUTO2:
		startAuto2();
		break;
	case ASSISTED1:
		startAssisted1();
		break;
	case ASSISTED2:
		startAssisted2();
		break;
	case MANUAL:
		startManual();
		break;
	default:
		break;
	}
}

/////////////////////////////////////////////////////////////////////////
static void startAuto1(voids)
{
	int i;
	checkPointsOnXAxis();
	if(PointsOnXAxis[0] !=(SENSORS_AMMOUNT+1))
	{
		if(PointsOnXAxis[1] !=(SENSORS_AMMOUNT+1))
		{
			if(!somethingAhead())
			{
				double inclination = checkInclination(allCoordinates[PointsOnXAxis[0]],allCoordinates[PointsOnXAxis[1]]);
				actuateOverInclination(inclination);
			}
			else
				trunRight();
		}
		else
		{
			if(!somethingAhead())
				moveFoward();
			else
				turnRight();
		}
	}
	return;
}

//////////////////////////////////////////////////////////////////////


static int PointsOnXAxis[2];
#define I_MIN_DISTANCE_BETWEEN_POINTS	0.5
/*Funcion que no recibe nada y chequea el arreglo de allCoordinates buscando los numeros negativos de x
y encontrando 2 puntos guarda el iterador de allCoordinates en PointsOnXAxis, ordenandolos de menor "y" de
coordinate_s a mayor "y" de coordinate_s
*/
static void checkPointsOnXAxis(void)
{
	int i;
	for (i =0; i<2;i++)			//Inicializo el arreglo de 2 ints en 0
		PointsOnXAxis[i]=SENSORS_AMMOUNT+1;
	for(i=0; (i<SENSORS_AMMOUNT) && (allCoordinates[i].x>0) ;i++);//Me muevo hasta encontrar un punto en x negativo o hasta recorrer todos los puntos obtenidos
	if(allCoordinates[i].x<0)	//Chequeo si salio del for porque un sensor encontro un pto negativo
	{
		PointsOnXAxis[0] = i;		//Guardo el numero del pto en el erreglo PointsOnXAxis
		bool exit = false;
		for(i++; (i<SENSORS_AMMOUNT) && (exit == false) ;i++)
		{
			if(allCoordinates[i].x <0)
			{
				if((allCoordinates[i].y)>(allCoordinates[PointsOnXAxis[0]].y + I_MIN_DISTANCE_BETWEEN_POINTS))
				{
					allCoordinates[1] = i;
					exit=true;
				}
				else if((allCoordinates[i].y)<(allCoordinates[PointsOnXAxis[0]].y - I_MIN_DISTANCE_BETWEEN_POINTS))
				{
					allCoordinates[1] = allCoordinates[0];
					allCoordinates[0] = i;
					exit = true;
				}
			}
		}
	}
	return;
}

/*Funcion que devuelve la pendiente que se forma entre 2 puntos
coordinate_s
*/
static double checkInclination(coordinate_s p0,coordinate_s p1)
{
	double deltaX = p0.x - p1.x;
	double deltaY = p0.y - p1.y;
	return (deltaX/deltaY);
}


/*Funcion que devuelve true si hay algo delante del robot
o false si no hay nada delante del robot*/
static bool somethingAhead(void)
{
	int i;
	bool isThereSomethingAhead =  false;
	for(i=0;(allCoordinates[i].y > 0) && (i < SENSORS_AMMOUNT);i++);
	if(i == (SENSORS_AMMOUNT -1))
		return false;
	else
		return true;
}

static void turnRight(void)
{
	//Hacer esta funcion!!!!!
}