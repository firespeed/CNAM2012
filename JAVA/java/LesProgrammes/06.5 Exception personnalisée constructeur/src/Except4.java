
public class Except4 {

	public static void main(String args[]) {
		try {
			Point a = new Point (1, 4) ;
			a.affiche() ;
			

			a = new Point (-3, 5) ;
			a.affiche() ;
		
		} catch (ErrConst e) {
			System.out.println (e.getMessage()) ;
			System.exit(-1);
		}

	}
}
