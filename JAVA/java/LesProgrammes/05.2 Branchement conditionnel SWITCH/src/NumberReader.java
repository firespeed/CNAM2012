class NumberReader
{
	String convertNum(int val) {
		switch (val) {
			case 0: return "zero";
			case 1: return "un";
			case 2: return "deux";
			case 3: return "trois";
			case 4: return "quatre";
			case 5: return "cinq";
			case 6: return "six";
			case 7: return "sept";
			case 8: return "huit" ;
			case 9: return "neuf";
			default: return " ";
		}
 	}

	public static void main (String args[]) {
		NumberReader n = new NumberReader();
		String num = n.convertNum(4)+" "+n.convertNum(1)+" "+n.convertNum(5);
		System.out.println("415 converti en " + num);
	}
}
