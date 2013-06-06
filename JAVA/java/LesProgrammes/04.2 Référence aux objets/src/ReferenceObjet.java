import java.awt.*;

public class ReferenceObjet {
	public static void main(String[] args) {
		Point pt1, pt2;
		pt1 = new Point(100,180);
		// Cette opération créé un alias et pas un 2° objet
		pt2 = pt1;
		
		pt1.x = 200;
		pt1.y = 200;
		
		System.out.println("Point 1 : "+pt1.x+", "+pt1.y);
		System.out.println("Point 2 : "+pt2.x+", "+pt2.y);
	}

}
