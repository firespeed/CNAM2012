import java.text.DateFormat;
import java.util.Date;
import java.util.Locale;

public class MainSimpleDate {

	
	public static void main(String args[]) {
	
		Date aujourdhui = new Date();
		
		DateFormat shortDateFormat = DateFormat.getDateTimeInstance(
					DateFormat.SHORT, DateFormat.SHORT);

		DateFormat shortDateFormatEN = DateFormat.getDateTimeInstance(
					DateFormat.SHORT,DateFormat.SHORT, new Locale("EN","en"));

		DateFormat mediumDateFormat = DateFormat.getDateTimeInstance(
					DateFormat.MEDIUM,DateFormat.MEDIUM);
		
		DateFormat mediumDateFormatEN = DateFormat.getDateTimeInstance(
					DateFormat.MEDIUM,DateFormat.MEDIUM, new Locale("EN","en"));

		DateFormat longDateFormat = DateFormat.getDateTimeInstance(
					DateFormat.LONG, DateFormat.LONG);
		
		DateFormat longDateFormatEN = DateFormat.getDateTimeInstance(
					DateFormat.LONG, DateFormat.LONG, new Locale("EN","en"));
		
		DateFormat fullDateFormat = DateFormat.getDateTimeInstance(
					DateFormat.FULL,DateFormat.FULL);

		DateFormat fullDateFormatEN = DateFormat.getDateTimeInstance(
					DateFormat.FULL,DateFormat.FULL, new Locale("EN","en"));
		
		
		System.out.println(shortDateFormat.format(aujourdhui));
		System.out.println(mediumDateFormat.format(aujourdhui));
		System.out.println(longDateFormat.format(aujourdhui));
		System.out.println(fullDateFormat.format(aujourdhui));
		System.out.println("");
		System.out.println(shortDateFormatEN.format(aujourdhui));
		System.out.println(mediumDateFormatEN.format(aujourdhui));
		System.out.println(longDateFormatEN.format(aujourdhui));
		System.out.println(fullDateFormatEN.format(aujourdhui));
	}	
}
