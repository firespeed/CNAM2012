import java.util.Calendar;


public class MainDate2 {

	public static void main(String args[]) {
		
		Calendar calendar = Calendar.getInstance();

		System.out.println("Jour : "+calendar.get(Calendar.DAY_OF_MONTH)); 
		System.out.println("Mois : "+calendar.get(Calendar.MONTH)); 
		System.out.println("Ann�e : "+calendar.get(Calendar.YEAR)); 

		System.out.println("Heure : "+calendar.get(Calendar.HOUR)); 
		System.out.println("Minute : "+calendar.get(Calendar.MINUTE)); 
		System.out.println("Heure : "+calendar.get(Calendar.SECOND)); 
		
		if (calendar.get(Calendar.MONTH ) == Calendar.MARCH) 
		{
			System.out.println("la date courante est en Mars"); 
		}
		
		// + 1mois � la date courante
		calendar.set(Calendar.MONTH, 3);
		System.out.println("Jour : "+calendar.get(Calendar.DAY_OF_MONTH)); 
		System.out.println("Mois : "+calendar.get(Calendar.MONTH)); 
		System.out.println("Ann�e : "+calendar.get(Calendar.YEAR)); 
	}
}
