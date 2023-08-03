#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

//crea la linea superior y la esquina superior derecha
void	build_line(int x, int y)
{
	int		i;
	char	e;
	char	l;

	i = 0;
	e = '*';
	l = '\\';
	// en esta condicion si y solo vale 1 entonces printara una linea, en caso que y > 1  printa una linea 
	// y ademas se relacionara, en otra funcion donde x > 1 para que printe la columna. La segunda condicion permite que el cuadrado se cree.
	if ((x > 1 && y == 1) || (x > 1 && y > 1))
	{
		//crea la linea superior
		while (i < x - 2)
		{
			putchar(e);
			i++;
		}
		//crea la esquina superior derecha
		putchar(l);
	}
}
// crea el interior del cuadrado. Por eso generamos espacios
void	space(int x)
{
	int		u;
	char	a;

	u = 0;
	a = ' ';
	while (u < x - 2)
	{
		putchar(a);
		u++;
	}
}
// Crea la columna izquierda, la derecha y invoca la funcion crear_espacio para generar el interior
void	build_column(int x, int y)
{
	int		i;
	char	t;
	char	e;

	i = 0;
	t = '\n';
	e = '*';
	while (i < y - 2)
	{
		//printa un salto de pagina
		putchar(t);
		//printa la columna
		putchar(e);
		//genera el espacio pasando por parametro int x -- x = ancho o linea
		space(x);
		// esta condicion evita crasheos tipo x = 2 and y = 2
		if (x > 1)
		{
			// printa la columna derecha
			putchar(e);
		}
		i++;
	}
}
// crea la linea inferior y la esquina inferior derecha
void	build_lower_line(int x)
{
	int		i;
	char	e;
	char	k;

	i = 0;
	e = '*';
	k = '/';
	while (i < x - 2)
	{
		// printa la linea inferior
		putchar(e);
		i++;
	}
	// esta condicion evita crasheos tipo x = 2 and y = 2
	if (x > 1)
	{
		// printa la esquina derecha
		putchar(k);
	}
}

void	builder(int x, int y)
{
	char	k;
	char	t;
	char	l;

	k = '/';
	t = '\n';
	l = '\\';
	// punto inicial - x and y tiene que tener valor para que printe alguna cosa. En cualquier caso siempre printa /
	if (x > 0 && y > 0)
	{
		//esquina superior izquierda donde se origina todo
		putchar(k);
		// crea la linea superior y la esquna superior derecha
		build_line(x, y);
		// esta condicion permite crear una columna o si x > 1 se relaciona con la condicion de crear_linea para que printe el cuadrado
		if ((x == 1 && y > 1) || (x > 1 && y > 1))
		{
			//crea la columna izquierda, a derecha y invoca la funcion crear_espacio para generar el interior
			build_column(x, y);
			//printa un salto de linea para poder printar a continuacion la esquina inferior izquierda
			putchar(t);
			//printa la esquina inferior izquierda que mencionaba anteriormente
			putchar(l);
			//crea la linea inferior y la esquina derecha
			build_lower_line(x);
		}
	}
}
