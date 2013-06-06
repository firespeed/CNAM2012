public class CoupleM {
	
	public static void main(String args[]) {
		Integer oi1 = 3;
		Double od1 = 2.5;

		Couple<Integer, Double> ch1 = new Couple<Integer, Double>(oi1, od1);
		ch1.affiche();
		
		Integer oi2 = 4;
		Couple<Integer, Integer> ch2 = new Couple<Integer, Integer>(oi1, oi2);
		ch2.affiche();

		Integer n = ch1.getPremier();
		System.out.println("premier element du couple ch1 = " + n);
	}
}