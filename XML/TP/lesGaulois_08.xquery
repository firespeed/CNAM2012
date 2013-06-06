xquery version "1.0";
<html>
<table>
	<tr>
		{
			for $x in /lesgaulois/villageois
			where $x/NOM="Asterix"
			return 
				<td>{$x/NOM}</td>
				<td>{$x/NOM_SPECIALITE}</td>
		}
	</tr>
</table>
</html>