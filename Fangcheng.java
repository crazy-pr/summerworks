package frist3;

public class Fangcheng {
	double a;
	double b;
	double c;
	double x1;
	double x2;
	public Fangcheng(double a1,double b1,double c1)
	{
		this.a =a1;
		this.b =b1;
		this.c=c1;
	}
	public void Solve()
	{
		double y1;
		double y2;
		double d;
		d=b*b-4*a*c;
		if(d>=0)
		{
			y1=(-b+Math.sqrt(d))/(2*a);
			y2=(-b-Math.sqrt(d))/(2*a);
			this.x1=y1;
			this.x2=y2;
			System.out.println("该方程的解为x1="+x1+"x2="+x2);
		}
		else
		{
			System.out.println("该方程无解");
		}
		
	}

}
