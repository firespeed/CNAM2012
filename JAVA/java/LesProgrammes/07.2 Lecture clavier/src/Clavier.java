import java.io.*;

public class Clavier {

	public static void main(String[] args) {
		String ligne_lue = null;
		try
		{
			//preparation pour la saisie
			InputStreamReader lecteur=new InputStreamReader(System.in);
			BufferedReader entree = new BufferedReader (lecteur);
			// Lecture de la ligne lue
			System.out.print("Entr�e une chaine de caract�res : ");
			ligne_lue = entree.readLine();
			// Affichage
			System.out.println("Ce que vous avez entr� : "+ligne_lue);
		}catch(IOException err)
		{
			System.exit(0);
		}
	}
}

