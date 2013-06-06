
public class LesChaines {


	
	public static void main (String args[]){

		String ch = "bonjour";
		int n = ch.length();
		System.out.println("Longueur de "+ch+" = "+n);
		
		
		for(int i=0;i<n;i++)
		{
			System.out.println("caractère en position "+i+" = "+ch.charAt(i));		
		}

		String mot = "Langage Java";
		for (char c : mot.toCharArray()) System.out.println(c);		

		mot = "anticonstitutionnellement" ;
		
		System.out.println("Pour le mot  "+mot);		
		n = mot.indexOf('t');
		System.out.println("position de 't' "+n);		
		n = mot.lastIndexOf('t') ;
		System.out.println("dernière position de 't' "+n);		
		n = mot.indexOf("ti") ; 		
		System.out.println("position de 'ti' "+n);		
		n = mot.lastIndexOf("ti");
		System.out.println("derniere position de 'ti' "+n);		
		n = mot.indexOf('x') ;
		System.out.println("position de 'x' "+n);
		
		
		String chaine1 = "une chaine";
		String chaine2 = "une chaine";
		
		System.out.println("chaine1 = chaine2 => "+(chaine1 == chaine2));
		System.out.println("chaine1.equals(chaine2) => "+(chaine1.equals(chaine2)));
	}

}
