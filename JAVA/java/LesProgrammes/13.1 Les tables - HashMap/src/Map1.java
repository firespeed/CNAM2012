import java.util.*;

public class Map1 {
	public static void main(String args[]) {
		HashMap<String, String> m = new HashMap<String, String>();
		m.put("c", "10");
		m.put("f", "20");
		m.put("k", "30");
		m.put("x", "40");
		m.put("p", "50");
		m.put("g", "60");
		System.out.println("map initial : " + m);

		// retrouver la valeur associee a la cle "f"
		String ch = m.get("f");

		System.out.println("valeur associee a f : " + ch);
		
		System.out.println("Ensemble des valeurs (attention, ici Collection, pas Set) : ");
		Collection<String> valeurs = m.values();
		System.out.println("liste des valeurs initiales : " + valeurs);
		valeurs.remove("30"); // on supprime la valeur "30" par la vue associee
		System.out.println("liste des valeurs apres sup : " + valeurs);
		System.out.println("---------------------------------------");

		System.out.println("ensemble des cles : ");
		Set<String> cles = m.keySet();
		System.out.println("liste des cles initiales : " + cles);
		System.out.println("map avant : " + m);
		cles.remove("p"); // on supprime la cle "p" par la vue associee
		System.out.println("liste des cles apres sup : " + cles);
		System.out.println("---------------------------------------");

		System.out.println("modification de la valeur associee a la cl� x :");
		String old = m.put("x", "25");

		if (old != null)
			System.out.println("valeur associee a x avant modif : " + old);		
		System.out.println("map apres modif de x : " + m);
		System.out.println("liste des valeurs apres modif de x : " + valeurs);
		System.out.println("---------------------------------------");
		System.out.println("map avant : " + m);
		System.out.println("Parcours des entrees (Map.Entry) du map jusqu�a trouver la valeur 20");
		System.out.println("et on supprime l�element correspondant (suppose exister) :");
		Set<Map.Entry<String, String>> entrees = m.entrySet();
		Iterator<Map.Entry<String, String>> iter = entrees.iterator();

		while (iter.hasNext()) {
			Map.Entry<String, String> entree = iter.next();
			String valeur = entree.getValue();
			if (valeur.equals("20")) {
				System.out.println("valeur 20 " + "trouvee en cle "
						+ entree.getKey());
				iter.remove(); // suppression sur la vue associee
				break;
			}
		}
		System.out.println("map apres sup element suivant 20 : " + m);
		System.out.println("---------------------------------------");
		

		System.out.println("on supprime l�element de cle 'g' :");
		System.out.println("map avant suppression g : " + m);
		m.remove("g");
		System.out.println("map apres suppression g : " + m);
		System.out.println("liste des cles apres suppression g : " + cles);
		System.out.println("liste des valeurs apres supp de g : " + valeurs);
		System.out.println("---------------------------------------");
	}
}