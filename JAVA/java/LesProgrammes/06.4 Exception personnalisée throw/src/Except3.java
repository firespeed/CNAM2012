
public class Except3 {

	public static void main(String args[]) {
		try {
			Point a = new Point (1, 4) ;
			a.affiche() ;
			

			a = new Point (-3, 5) ;
			a.affiche() ;
		
		} catch (ErrConst e) {
			System.out.println("Erreur construction ");
			System.out.println (" coordonnees souhaitees : " + e.abs + " " + e.ord) ;
			System.exit(-1);
		}

	}
}
