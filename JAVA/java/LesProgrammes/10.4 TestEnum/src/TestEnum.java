import java.util.*;


public class TestEnum {

	enum Jour { lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche }
	
	public static void main (String args[]){
		
		System.out.println("Liste des valeurs du type enum Jour : ");
		
		for(Jour j : Jour.values())
		{
			System.out.println(" position : "+j.ordinal()+" - valeur "+j);			
		}
		
		
	}
}
