// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>

#include <iostream>
int q_estado;

using namespace std;

int main()

{
	

	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;

	conectar = mysql_init(0);

	conectar = mysql_real_connect(conectar, "localhost", "use_empresaa", "empresa3$%", "db_empresa2", 3306, NULL, 0);

	if (conectar) {

		//cout << "Conexion Exitosa..." << endl;
		string producto;
		string descripcion;
		string id_marca;
		string precio_costo;
		string precio_venta;
		string existencia;
		string fecha_ingreso;
		string insert;
		string marca;
		string id_marca2;
		int opcion;
		cout << "--------------ingrese la opcion que desee: ----------------" << endl;
		cout << " 1. realizar consultas en la tabla productos....." << endl;
		cout << " 2. realizar consultas en la tabla marcas...." << endl;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			cout << " para insertar ingrese..." << endl;
			cout << " " << endl;
			cout << " ingrese producto" << endl;
			cin >> producto;
			cout << " ingrese id_marca" << endl;
			cin >> id_marca2;
			cout << "ingrese descripcion" << endl;
			cin >> descripcion;
			cout << " ingrese precio_costo" << endl;
			cin >> precio_costo;
			cout << " ingrese precio_venta" << endl;
			cin >> precio_venta;
			cout << " ingrese cuanto hay en existencia" << endl;
			cin >> existencia;
			cout << " ingrese fecha_ingreso del producto" << endl;
			cin >> fecha_ingreso;

			insert = " insert into productos(producto,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso)values('" + producto + "','" + descripcion + "','" + precio_costo + "', '" + precio_venta + "','" + existencia + "', '" + fecha_ingreso + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "ingreso Exitoso..." << endl;

			}
			else {

				cout << "xxxxx error de  ingreso xxxx" << endl;
			}
			cout<< " " <<endl;
			cout << " " << endl;
			cout << " " << endl;

			cout << " para ver ingresos ingrese..." << endl;
			cout << " " << endl;

			string consulta = " select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(conectar, c);
			if (!q_estado) {
				resultado = mysql_store_result(conectar);
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}
			cout << " " << endl;
			cout << " " << endl;
			cout << " " << endl;

			string id_productos;
			string sql;
			cout << " para actualizar ingrese..." << endl;
			cout << " " << endl;

			cout << " ingrese id" << endl;
			cin >> id_productos;
			cout << " ingrese producto" << endl;
			cin >> producto;
			cout << " ingrese id_marca" << endl;
			cin >> id_marca2;
			cout << "ingrese descripcion" << endl;
			cin >> descripcion;
			cout << " ingrese precio_costo" << endl;
			cin >> precio_costo;
			cout << " ingrese precio_venta" << endl;
			cin >> precio_venta;
			cout << " ingrese cuanto hay en existencia" << endl;
			cin >> existencia;
			cout << " ingrese fecha_ingreso del producto" << endl;
			cin >> fecha_ingreso;
			sql = " UPDATE productos   SET producto='" + producto + "', descripcion='" + descripcion + "', precio_costo='" + precio_costo + "', precio_venta='" + precio_venta + "', existencia='" + existencia + "', fecha_ingreso= '" + fecha_ingreso + "' WHERE id_productos= '" + id_productos + "'";
			const char* a = sql.c_str();
			q_estado = mysql_query(conectar, a);
			if (!q_estado) {
				cout << " actualizacion Exitosa..." << endl;

			}
			else {

				cout << "xxxxx error de  actualizacion xxxx" << endl;
			}
			cout << " " << endl;
			cout << " " << endl;
			cout << " " << endl;

			string sel;
			cout << " para eliminar ingrese..." << endl;
			cout << " " << endl;

			cout << "ingrese id" <<endl;
			cin >> id_productos;
			sel = " DELETE FROM productos   WHERE id_productos= '" + id_productos + "'";
			const char* f = sel.c_str();
			q_estado = mysql_query(conectar, f);
			if (!q_estado) {
				cout << " se elimino con existo..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}


			break;

		}

			  

	case 2: {
		cout << " para insertar ingrese..." << endl;
		cout << " " << endl;

		cout << " ingrese marca: " << endl;
		cin >> marca;

		insert = " insert into marcas(marca)values('" + marca + "')";
		const char* o = insert.c_str();
		q_estado = mysql_query(conectar, o);
		if (!q_estado) {
			cout << "ingreso Exitoso..." << endl;

		}
		else {

			cout << "xxxxx error de  ingreso xxxx" << endl;
		}
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;

		cout << " para ver ingresos ingrese..." << endl;
		cout << " " << endl;

		string consulta2 = " select * from marcas";
		const char* p = consulta2.c_str();
		q_estado = mysql_query(conectar, p);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << endl;
			}

		}
		else {

			cout << "xxxxx error de  consulta xxxx" << endl;
		}
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;

		
		string sol;
		string id_marcas;
		cout << " para actualizar ingrese..." << endl;
		cout << " " << endl;

		cout << " ingrese id" << endl;
		cin >> id_marcas;
		cout << "ingrese marca nueva" << endl;
		cin >> marca;
		sol = " UPDATE marcas   SET marca='" + marca + "'WHERE id_marcas= '" + id_marcas + "'";
		const char* z = sol.c_str();
		q_estado = mysql_query(conectar, z);
		if (!q_estado) {
			cout << " actualizacion Exitosa..." << endl;

		}
		else {

			cout << "xxxxx error de  actualizacion xxxx" << endl;
		}
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;
		
		string sqw;
		cout << " para eliminar ingrese..." << endl;
		cout << " " << endl;

		cout << "ingrese id" << endl;
		cin >> id_marcas;
		sqw = " DELETE FROM marcas   WHERE id_marcas= '" + id_marcas + "'";
		const char* n = sqw.c_str();
		q_estado = mysql_query(conectar, n);
		if (!q_estado) {
			cout << " se elimino con existo..." << endl;

		}
		else {

			cout << "xxxxx error al eliminar xxxx" << endl;
		}

		
		break;
	}

		}
		

	}
	

	else {

		cout << " xxx Error en la Conexion xxxx" << endl;

	}

	system("pause");

	return 0;
}

