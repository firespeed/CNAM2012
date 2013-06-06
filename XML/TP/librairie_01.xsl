<?xml version="1.0" encoding="ISO-8859-1"?> 
<xsl:stylesheet version="1.0" 
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="librairie">
		<html>
			<head>
				<title>Les livres de la librairie</title>
			</head>
			<body>
				<xsl:apply-templates />
			</body>
		</html>
	</xsl:template>
		
	<xsl:template match="livre">
<ul>		
		<li><xsl:value-of select="titre"/></li>
		<li><xsl:value-of select="auteur"/></li>	
		<li><xsl:value-of select="editeur"/></li>	
</ul>
	</xsl:template>
	
</xsl:stylesheet>




