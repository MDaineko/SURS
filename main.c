#include <stdio.h>
#include <math.h>
#include <locale.h>
 
float f(float x)
{
    float rez = sin(x*x+2*x);
	return rez;	
}
 
int main() {
	
	setlocale(LC_ALL, "Russian");
    
	float a, b, eps;	//������ � ������� ������� �������������� (a, b), ����������� (eps).
	printf ("Enter the left integration boundary a = ");
    scanf ("%f", &a);
    printf ("\nEnter the right integration boundary b = ");
    scanf ("%f", &b);
    printf ("\nEnter the required accuracy eps = ");
    scanf ("%f", &eps);

	float I = eps+1, I1 = 0;	//I- ���������� ������������ �������� ���������, I1-�����, � ������� N.
	for (int N = 2; (N <= 4) || (fabs(I1-I) > eps); N *= 2)
	{
		float h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b-a)/(2*N);		//��� ��������������.
		for (int i = 1; i <= 2*N-1; i += 2)
		{   
			sum4 += f(a+h*i);		//�������� � ��������� ���������, ������� ����� �������� �� 4.
			sum2 += f(a+h*(i+1));		//�������� � ������� ���������, ������� ����� �������� �� 2.
		}
		sum = f(a)+4*sum4+2*sum2-f(b);	//�������� �������� f(b), ��� ��� ����� ��������� ��� ������. 
		I = I1;
		I1 = (h/3)*sum;
	}
	printf ("\nIntegral = %f", I1);
	
	return 0;
}
