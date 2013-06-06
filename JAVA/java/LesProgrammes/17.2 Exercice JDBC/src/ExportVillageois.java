import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;


public class ExportVillageois {

	
	public static void main(String[] args) {
		String requete;
		String ligne;
		
		try
    	{
    		Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/lesgaulois","root","");
			Statement st = conn.createStatement();
	    	
			requete = "SELECT * FROM villageois, specialite WHERE villageois.ID_SPECIALITE = specialite.ID_SPECIALITE ORDER BY NOM";					
			
			ResultSet rec = st.executeQuery(requete);

			File sortie = new File("LesVillageois.csv");

            FileWriter fw = new FileWriter(sortie);
            BufferedWriter out = new BufferedWriter(fw);
			
			// Entete
			ligne = "ID_VILLAGEOIS;NOM_VILLAGEOIS;ADRESSE;SPECIALITE"+"\n";
			out.write(ligne);
			while(rec.next())
	    	{
				ligne = rec.getInt("ID_VILLAGEOIS")+";"+rec.getString("NOM")+";"+rec.getString("ADRESSE")+";"+rec.getString("NOM_SPECIALITE")+"\n";
				
				out.write(ligne);
	    		
	    	}
			out.close();
			st.close();
		}
		catch (Exception e)		    
		{
			System.out.println("ERREUR " + e.toString());
		}

	}

}
