import java.util.*;

public class EnsPt1 {
	public static void main(String args[]) {
		Point p1 = new Point(1, 3), p2 = new Point(2, 2);
		Point p3 = new Point(4, 5), p4 = new Point(1, 8);
		Point p[] = { p1, p2, p1, p3, p4, p3 };

		HashSet<Point> ens = new HashSet<Point>();
		for (Point px : p)
		{
			System.out.print("le point ");
			px.affiche();
			boolean ajoute = ens.add(px);
			if (ajoute)
				System.out.println(" a ete ajoute");
			else
				System.out.println("est deja present");
			System.out.print("ensemble = ");
			affiche(ens);
		}
	}

	public static void affiche(HashSet<Point> ens)
	{
		Iterator<Point> iter = ens.iterator();
		while (iter.hasNext()) {
			Point p = iter.next();
			p.affiche();
		}
		System.out.println();
	}
}
