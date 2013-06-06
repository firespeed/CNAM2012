<?xml version="1.0" encoding="ISO-8859-1"?> 
<xsl:stylesheet version = '1.0' 
	xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

<!-- Définition de l'entête correpondant à l'élément racine -->
<xsl:template match="/">
	<html>
		<head>
		Au coeur du langage XSLT
			<title><xsl:value-of select="/Concert/Entête"/></title>
		</head>
		<body bgcolor="white" text="black">
			<xsl:apply-templates/>
		</body>
	</html>
</xsl:template>

<!-- Définition des templates -->
<xsl:template match="/bibliographoi/livre[1]">
	<p> <xsl:value-of select="."/> Titre</p>
</xsl:template>


</xsl:stylesheet>