
public class EnumValeurs {

	enum Jour{lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche};
	public static void main(String args[])
	{
		System.out.println("Liste des valeurs du type jour : ");
	
		for(Jour j : Jour.values())
		{
			System.out.println(j.toString());
		}
	}
}
