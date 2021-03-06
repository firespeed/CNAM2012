<?xml version="1.0" encoding="UCS-2"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="html" encoding="ISO-8859-1"/>

	<xsl:template match="/">
		<html>
			<head>
				<title>
					<xsl:value-of select="/Concert/Entête"/>
				</title>
			</head>
			<body bgcolor="white" text="black">
				<xsl:apply-templates/>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="Entête">
		<p>
			<xsl:value-of select="."/>présentent
		</p>
	</xsl:template>
	
	<xsl:template match="Lieu">
		<H4 align="center">
			<xsl:value-of select="."/>
		</H4>
	</xsl:template>
	
	<xsl:template match="Date">
		<H1 align="center">
			Concert du <xsl:value-of select="."/>
		</H1>
	</xsl:template>
	
	<xsl:template match="Ensemble">
		<H2 align="center">
			Ensemble
			<xsl:value-of select="."/>
		</H2>
	</xsl:template>
	
	<xsl:template match="Compositeurs">
		<H3 align="center">
			Oeuvres de <br/>
		<xsl:value-of select="."/>
		</H3>	
	</xsl:template>

</xsl:stylesheet>
