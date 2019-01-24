#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double distance(double latitude1, double longitude1, double latitude2, double longitude2, double height);
double truespeed(double h,double vel);
int main()
{
  float lat1,lat2,lon1,lon2,hmax,hmin;
  float time,temp,att;
  printf(" Enter latitude1 longitude1 latitude 2 longitude2\n");
  scanf("%f %f %f %f",&lat1,&lon1,&lat2,&lon2);
  printf(" Enter the maximum and minimum height for vertical velocity measurement\n");
  scanf("%f %f",&hmax,&hmin);
  float hd = hmax - hmin,h = (hmax + hmin)/2;
  printf(" Enter the time taken in seconds\n");
  scanf("%f",&time);
  double dist = distance(lat1,lon1,lat2,lon2,h);
  printf(" The distance is %f\n",dist);
  double horizontal = dist / time;
  double vertical = hd /(time);
  printf(" Horizontal velocity is %f Vertical velocity is %f\n",horizontal,vertical);
  double fvelocity = sqrt(horizontal * horizontal + vertical * vertical);
  printf(" final velocity is %f\n",fvelocity);
  printf("Enter the Temperature in Kelvin\n");
  scanf("%f",&temp);
  double airspeed = truespeed(temp,fvelocity);
  printf(" Airspeed is %f\n",airspeed);
  att = (atan(vertical / horizontal));//* 180)/ 3.14159265358979323846;
  printf(" The attitude is %f\n degrees",att);
  return(0);
}
double distance(double latitude1, double longitude1, double latitude2, double longitude2, double height)
{
	double r = 6378100;
  double surf1 =  4 * 3.14159265358979323846 * r * r;
  double surf2 =  4 * 3.14159265358979323846 * (r + height) * (r + height);
  double rem = surf2/surf1;
	double rho1 = (r ) * cos(latitude1);
	double z1 = (r ) * sin(latitude1);
	double x1 = rho1 * cos(longitude1);
	double y1 = rho1 * sin(longitude1);
	double rho2 = (r) * cos(latitude2);
	double z2 = (r ) * sin(latitude2);
	double x2 = rho2 * cos(longitude2);
	double y2 = rho2 * sin(longitude2);
	double dot = (x1 * x2 + y1 * y2 + z1 * z2);
	double cos_theta = dot / (r * r );
	double theta = acos(cos_theta);
	return ( r ) * theta * sqrt(rem);
}
double truespeed(double temp,double vel)
{
  double sound;
  double gamma = 1.4,rvalue = 286;
  sound = gamma * rvalue * temp;
  double air = vel * 339.5/sqrt(sound);
  return(air);
}
