#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class Car {
public:
  string id;     //���ƺ���
  int pos_park;  //������ͣ�����е�λ��
  bool isArriving;
  bool isLeaving;
  tm *time_arrive; //����ʱ��
  tm *time_in;     //�볡ʱ��
  Car *next;       //�γ�ָ��, ���ڱ��ͣ������

  Car() {}
  Car(string carID);
  void Car2Queue();            //����ʻ�����
  void Car2Park();             //����ʻ��ͣ����
  double Fee(); //�����볡ʱ�������
};

//ͣ������, ʹ��ջ��ʵ��
class ParkingLot {
public:
  int len;      //ͣ��������
  Car **cars;   //����ջ, ����Ϊlen
  Car **buffer; //��������ʱ�Ļ�����, ����Ϊlen
  int lastCar;  //����ջ��

  ParkingLot(int len);
  bool CarIn(string carID);            //������������ͣ����
  bool CarfromQueue(Car *newCar);      //������λ��������ͣ����
  bool CarOut(string carID, double *fee); //�����뿪ͣ����
  void FullWarning() {}                //ͣ������������
  void NullWarning() {}                //δ�ҵ���������
  Car *findCar(string carID);          //��������
  int getCarPosition(string carID);    //��ȡ��������λ��
  void getStatus(); //��ʾ��ǰͣ����״̬(������Ϣ)
};

//�����, ʹ�ö���������ʵ��
class Lane {
public:
  Car *front; //����׳�ָ��
  Car *rear;  //���β��ָ��

  Lane() { rear = front = NULL; }
  void CarIn(string carID);         //��������������
  bool Car2Park(ParkingLot *park);  //�׳�����ͣ����
  Car *findCar(string carID);       //��������
  int getLength();                  //��ȡ��ǰ���г���
  int getCarPosition(string carID); //��ȡ��������λ��
  void getStatus();                 //��ʾ��ǰ���״̬(������Ϣ)
};