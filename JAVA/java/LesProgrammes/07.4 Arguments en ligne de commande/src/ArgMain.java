
public class ArgMain {

	public static void main(String[] args) {

		int nbArgs = args.length;
		if(nbArgs == 0) System.out.println("Pas d'argument");
		else
		{
			for(int i=0; i < nbArgs; i++)
				System.out.println("argument n° "+i+" = "+ args[i]);
		}
	}

}
