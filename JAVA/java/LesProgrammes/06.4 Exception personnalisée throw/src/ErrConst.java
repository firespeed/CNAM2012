
class ErrConst extends Exception {

	public int abs, ord;

	ErrConst(int abs, int ord) {
		this.abs = abs;
		this.ord = ord;
	}
}