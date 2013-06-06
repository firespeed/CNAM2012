 class CopyArrayWhile {
	public static void main (String args[]) {
		int[] arrayl = { 5, 7, 3, 6, 0, 3, 2, 1 };
		float[] array2 = new float[arrayl.length];

		System.out.print("arrayl: [ ");
		for (int i = 0; i < arrayl.length; i++) {
			System.out.print(arrayl[i] +      " ");
		}
		System.out.println("]");

		System.out.print("array2: [ ");
		int count = 0;
		while (count < arrayl.length && arrayl[count] != 0) {
			array2[count] = (float) arrayl[count];
			System.out.print(array2[count++] + " ");
		}
		System.out.println("]");
	}
}