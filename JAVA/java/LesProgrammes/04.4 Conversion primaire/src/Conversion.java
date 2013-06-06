
public class Conversion {

	
	public static void main (String[] args)
	{
		byte a = 120;
		double b = 10.54;

		byte c =  (byte) (a + b);
		System.out.println("c = "+c);
		
		double d =  (double) (a + b);
		System.out.println("d = "+d);
		
	}
	
}
