
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

sensorInfo_s allInfo[SENSORS_AMMOUNT];	//tiene que estar creado en algun lugar. NO GLOBAL
coordinate_s allCoordinates[SENSORS_AMMOUNT];

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
	int left;
	left = checkLeft();
	int leftAndUp = checkLefAndUp();
	double cosHipo;
	int up = checkUp();

	//Necesito las funciones de malee

	if (up > MIN_DISTANCE)
	{
		if (((cosHipo = leftAndUp * cos(ANGLE)) > (left - 1)) && (cosHipo) < (left + 1) && up > MIN_DISTANCE)
			moveFoward();
		else if (cosHipo < (left - 1))
			turn((int)(cosHipo - left));
		else if (cosHipo >(left + 1))
			trun((int)(cosHipo - left));
	}
	else
	{
		if (((cosHipo = leftAndUp * cos(ANGLE)) > (left - 1)) && (cosHipo) < (left + 1) && up > MIN_DISTANCE)
			turn(IAN_RIGHT);
		else if (cosHipo < (left - 1))
			turn((int)(cosHipo - left));
		else
			turn(IAN_RIGHT);
	}
	return;
}


//////////////////////////////////////////////////////////////////////////
static void turn(int definer)
{
	if (definer >= 0)
	{
		switch (definer) {
		case 0:
			S_setActuatorMovUnproc(RIGHT_MOTOR, 2);
		case 1:
			S_setActuatorMovUnproc(RIGHT_MOTOR, 10);
			break;
		case 2:
			S_setActuatorMovUnproc(RIGHT_MOTOR, 12);
			break;
		case 3:
			S_setActuatorMovUnproc(RIGHT_MOTOR, 15);
			break;
		case 4:
			S_setActuatorMovUnproc(RIGHT_MOTOR, 17);
			break;
		case 5:
			S_setActuatorMovUnproc(RIGHT_MOTOR, 20);
			break;
		default:
			S_setActuatorMovUnproc(RIGHT_MOTOR, 22);
			break;
		}
	}
	else
	{
		switch (definer) {
		case -1:
			S_setActuatorMovUnproc(LEFT_MOTOR, 10);
			break;
		case -2:
			S_setActuatorMovUnproc(LEFT_MOTOR, 12);
			break;
		case -3:
			S_setActuatorMovUnproc(LEFT_MOTOR, 15);
			break;
		case -4:
			S_setActuatorMovUnproc(LEFT_MOTOR, 17);
			break;
		case -5:
			S_setActuatorMovUnproc(LEFT_MOTOR, 20);
			break;
		default:
			S_setActuatorMovUnproc(LEFT_MOTOR, 22);
			break;
		}
	}
	return;
}