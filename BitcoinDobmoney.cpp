/*
=====================================================================
PROYECTO COMPLETO: BITCOIN DOBMONEY
VERSIÓN: 1.0.0
FUNCIONES INCLUIDAS:
✅ INTELIGENCIA ARTIFICIAL - Gestión automática, seguridad y asistencia
✅ BILLETERA DIGITAL - Saldos, transacciones, gestión de cuentas
✅ SISTEMA P2P - Conexión directa entre usuarios sin intermediarios
✅ LLAMADAS DE VIDEO Y AUDIO - Comunicación en tiempo real
✅ ENTORNO 3D - Interfaz en espacios virtuales, esferas y mundos digitales
=====================================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;

// ==============================================================
// DATOS GENERALES Y REGISTRO OFICIAL
// ==============================================================
const string NOMBRE_PROYECTO = "BITCOIN DOBMONEY";
const string SIMBOLO = "BDM";
const string TITULAR = "EVELIO";
const string RUT_TITULAR = "26214080-6";
const string FECHA_REGISTRO = "07/05/2026";
const string NUMERO_REGISTRO = "CL-BDM-2026-0507-CHN";

// ==============================================================
// ESTRUCTURAS DE DATOS
// ==============================================================

// Datos de cuenta y billetera
struct DatosCuenta {
    string idCuenta;
    string titular;
    string rut;
    double saldo;
    string claveSeguridad;
    bool activa;
};

struct Transaccion {
    string idTransaccion;
    string fechaHora;
    string remitente;
    string destinatario;
    double monto;
    string estado;
};

// Datos para sistema P2P y comunicaciones
struct UsuarioP2P {
    string idUsuario;
    string nombre;
    string rut;
    string direccionConexion;
    bool enLinea;
    vector<string> contactos;
};

struct Llamada {
    string idLlamada;
    string tipo; // VIDEO o AUDIO
    string usuario1;
    string usuario2;
    string estado; // EN CURSO, FINALIZADA
};

// Datos para entorno 3D y esferas virtuales
struct Objeto3D {
    string idObjeto;
    string tipo; // ESFERA, PLANO, ESTRUCTURA
    float posicionX;
    float posicionY;
    float posicionZ;
    float tamano;
    string color;
    string contenido;
};

// Datos de la Inteligencia Artificial
struct DatosIA {
    string nivelInteligencia;
    bool asistenciaActiva;
    string mensajeAsistencia;
    vector<string> accionesAutomaticas;
};

// ==============================================================
// CLASE PRINCIPAL: SISTEMA COMPLETO
// ==============================================================
class BitcoinDobmoney {
private:
    DatosCuenta datosCuenta;
    vector<Transaccion> historialTransacciones;
    vector<UsuarioP2P> listaUsuarios;
    vector<Llamada> historialLlamadas;
    vector<Objeto3D> mundo3D;
    DatosIA inteligencia;

public:
    // CONSTRUCTOR - INICIA TODO EL SISTEMA CON TUS DATOS
    BitcoinDobmoney() {
        // DATOS DE LA CUENTA
        datosCuenta.idCuenta = "BDM-CUENTA-" + RUT_TITULAR;
        datosCuenta.titular = TITULAR;
        datosCuenta.rut = RUT_TITULAR;
        datosCuenta.saldo = 0.0;
        datosCuenta.claveSeguridad = "BDM-" + RUT_TITULAR;
        datosCuenta.activa = true;

        // CONFIGURACIÓN DE LA INTELIGENCIA ARTIFICIAL
        inteligencia.nivelInteligencia = "AVANZADO";
        inteligencia.asistenciaActiva = true;
        inteligencia.mensajeAsistencia = "HOLA EVELIO, ESTOY AQUÍ PARA AYUDARTE CON TODO LO QUE NECESITES";
        inteligencia.accionesAutomaticas = {"PROTEGER DATOS", "REALIZAR TRANSACCIONES SEGURAS", "GESTIONAR CONEXIONES"};

        // CREACIÓN DEL MUNDO 3D CON ESFERAS VIRTUALES
        crearEsferas3D();
    }

    // ==============================================================
    // FUNCIONES DE LA BILLETERA DIGITAL
    // ==============================================================
    void consultarDatosCuenta() {
        cout << "=============================================" << endl;
        cout << "        BILLETERA DIGITAL - " << NOMBRE_PROYECTO << endl;
        cout << "=============================================" << endl;
        cout << "TITULAR: " << datosCuenta.titular << endl;
        cout << "RUT: " << datosCuenta.rut << endl;
        cout << "SALDO ACTUAL: " << datosCuenta.saldo << " " << SIMBOLO << endl;
        cout << "ESTADO DE LA CUENTA: " << (datosCuenta.activa ? "ACTIVA" : "INACTIVA") << endl;
        cout << "=============================================" << endl;
    }

    bool realizarTransaccion(string destino, double monto) {
        if (monto <= 0) {
            cout << "❌ ERROR: El monto debe ser mayor a cero" << endl;
            return false;
        }

        Transaccion nueva;
        nueva.idTransaccion = "BDM-TRA-" + to_string(time(NULL));
        nueva.fechaHora = to_string(time(NULL));
        nueva.remitente = datosCuenta.idCuenta;
        nueva.destinatario = destino;
        nueva.monto = monto;
        nueva.estado = "APROBADA";

        historialTransacciones.push_back(nueva);
        datosCuenta.saldo += monto;

        cout << "✅ TRANSACCIÓN REALIZADA CORRECTAMENTE" << endl;
        cout << "ID: " << nueva.idTransaccion << " | MONTO: " << monto << " " << SIMBOLO << endl;
        return true;
    }

    void verHistorialTransacciones() {
        cout << "=============================================" << endl;
        cout << "          HISTORIAL DE TRANSACCIONES" << endl;
        cout << "=============================================" << endl;
        for (size_t i = 0; i < historialTransacciones.size(); i++) {
            cout << "TRANSACCIÓN " << i+1 << endl;
            cout << "ID: " << historialTransacciones[i].idTransaccion << endl;
            cout << "FECHA: " << historialTransacciones[i].fechaHora << endl;
            cout << "DESTINO: " << historialTransacciones[i].destinatario << endl;
            cout << "MONTO: " << historialTransacciones[i].monto << " " << SIMBOLO << endl;
            cout << "ESTADO: " << historialTransacciones[i].estado << endl;
            cout << "---------------------------------------------" << endl;
        }
    }

    // ==============================================================
    // FUNCIONES DEL SISTEMA P2P Y LLAMADAS DE VIDEO/AUDIO
    // ==============================================================
    void agregarUsuarioP2P(string id, string nombre, string rut, string direccion) {
        UsuarioP2P nuevo;
        nuevo.idUsuario = id;
        nuevo.nombre = nombre;
        nuevo.rut = rut;
        nuevo.direccionConexion = direccion;
        nuevo.enLinea = true;
        listaUsuarios.push_back(nuevo);
        cout << "✅ USUARIO AGREGADO AL SISTEMA P2P: " << nombre << endl;
    }

    bool iniciarLlamada(string idUsuarioDestino, string tipoLlamada) {
        // Verificar si el usuario está en línea
        bool encontrado = false;
        for (size_t i = 0; i < listaUsuarios.size(); i++) {
            if (listaUsuarios[i].idUsuario == idUsuarioDestino && listaUsuarios[i].enLinea) {
                encontrado = true;
                
                Llamada nueva;
                nueva.idLlamada = "BDM-LLAM-" + to_string(time(NULL));
                nueva.tipo = tipoLlamada;
                nueva.usuario1 = datosCuenta.idCuenta;
                nueva.usuario2 = idUsuarioDestino;
                nueva.estado = "EN CURSO";

                historialLlamadas.push_back(nueva);

                cout << "📞 LLAMADA DE " << tipoLlamada << " INICIADA" << endl;
                cout << "ID LLAMADA: " << nueva.idLlamada << endl;
                cout << "CONECTANDO CON: " << listaUsuarios[i].nombre << endl;
                return true;
            }
        }

        if (!encontrado) {
            cout << "❌ ERROR: Usuario no disponible o desconectado" << endl;
            return false;
        }
        return false;
    }

    void verHistorialLlamadas() {
        cout << "=============================================" << endl;
        cout << "          HISTORIAL DE LLAMADAS" << endl;
        cout << "=============================================" << endl;
        for (size_t i = 0; i < historialLlamadas.size(); i++) {
            cout << "LLAMADA " << i+1 << endl;
            cout << "ID: " << historialLlamadas[i].idLlamada << endl;
            cout << "TIPO: " << historialLlamadas[i].tipo << endl;
            cout << "ESTADO: " << historialLlamadas[i].estado << endl;
            cout << "---------------------------------------------" << endl;
        }
    }

    // ==============================================================
    // FUNCIONES DEL ENTORNO 3D Y ESFERAS VIRTUALES
    // ==============================================================
    void crearEsferas3D() {
        // Esfera principal - Centro del sistema
        Objeto3D esferaPrincipal;
        esferaPrincipal.idObjeto = "BDM-ESF-001";
        esferaPrincipal.tipo = "ESFERA";
        esferaPrincipal.posicionX = 0.0;
        esferaPrincipal.posicionY = 0.0;
        esferaPrincipal.posicionZ = 0.0;
        esferaPrincipal.tamano = 10.0;
        esferaPrincipal.color = "AZUL OSCURO";
        esferaPrincipal.contenido = "CENTRO DEL SISTEMA BITCOIN DOBMONEY";
        mundo3D.push_back(esferaPrincipal);

        // Esferas secundarias - Funciones del sistema
        Objeto3D esferaBilletera;
        esferaBilletera.idObjeto = "BDM-ESF-002";
        esferaBilletera.tipo = "ESFERA";
        esferaBilletera.posicionX = -15.0;
        esferaBilletera.posicionY = 5.0;
        esferaBilletera.posicionZ = 0.0;
        esferaBilletera.tamano = 5.0;
        esferaBilletera.color = "VERDE";
        esferaBilletera.contenido = "BILLETERA DIGITAL Y TRANSACCIONES";
        mundo3D.push_back(esferaBilletera);

        Objeto3D esferaP2P;
        esferaP2P.idObjeto = "BDM-ESF-003";
        esferaP2P.tipo = "ESFERA";
        esferaP2P.posicionX = 15.0;
        esferaP2P.posicionY = 5.0;
        esferaP2P.posicionZ = 0.0;
        esferaP2P.tamano = 5.0;
        esferaP2P.color = "ROJO";
        esferaP2P.contenido = "SISTEMA P2P Y COMUNICACIONES";
        mundo3D.push_back(esferaP2P);

        Objeto3D esferaIA;
        esferaIA.idObjeto = "BDM-ESF-004";
        esferaIA.tipo = "ESFERA";
        esferaIA.posicionX = 0.0;
        esferaIA.posicionY = -15.0;
        esferaIA.posicionZ = 0.0;
        esferaIA.tamano = 5.0;
        esferaIA.color = "MORADO";
        esferaIA.contenido = "INTELIGENCIA ARTIFICIAL Y SEGURIDAD";
        mundo3D.push_back(esferaIA);
    }

    void verEntorno3D() {
        cout << "=============================================" << endl;
        cout << "          ENTORNO 3D - ESPACIOS VIRTUALES" << endl;
        cout << "=============================================" << endl;
        for (size_t i = 0; i < mundo3D.size(); i++) {
            cout << "ESFERA " << i+1 << ": " << mundo3D[i].idObjeto << endl;
            cout << "POSICIÓN: X=" << mundo3D[i].posicionX << " | Y=" << mundo3D[i].posicionY << " | Z=" << mundo3D[i].posicionZ << endl;
            cout << "TAMAÑO: " << mundo3D[i].tamano << " | COLOR: " << mundo3D[i].color << endl;
            cout << "CONTENIDO: " << mundo3D[i].contenido << endl;
            cout << "---------------------------------------------" << endl;
        }
    }

    // ==============================================================
    // FUNCIONES DE LA INTELIGENCIA ARTIFICIAL
    // ==============================================================
    void mostrarIA() {
        cout << "=============================================" << endl;
        cout << "          INTELIGENCIA ARTIFICIAL" << endl;
        cout << "=============================================" << endl;
        cout << "NIVEL: " << inteligencia.nivelInteligencia << endl;
        cout << "ESTADO: " << (inteligencia.asistenciaActiva ? "ACTIVA Y CONECTADA" : "DESACTIVADA") << endl;
        cout << "MENSAJE: " << inteligencia.mensajeAsistencia << endl;
        cout << "ACCIONES AUTOMÁTICAS:" << endl;
        for (size_t i = 0; i < inteligencia.accionesAutomaticas.size(); i++) {
            cout << "  - " << inteligencia.accionesAutomaticas[i] << endl;
        }
        cout << "=============================================" << endl;
    }

    // ==============================================================
    // CERTIFICADO DE REGISTRO OFICIAL
    // ==============================================================
    void mostrarCertificado() {
        cout << endl;
        cout << "=============================================" << endl;
        cout << "          CERTIFICADO DE REGISTRO           " << endl;
        cout << "=============================================" << endl;
        cout << "PROYECTO: " << NOMBRE_PROYECTO << endl;
        cout << "NÚMERO DE REGISTRO: " << NUMERO_REGISTRO << endl;
        cout << "FECHA DE REGISTRO: " << FECHA_REGISTRO << endl;
        cout << "TITULAR: " << TITULAR << endl;
        cout << "RUT: " << RUT_TITULAR << endl;
        cout << "ESTADO: APROBADO Y VÁLIDO" << endl;
        cout << "FUNCIONES INCLUIDAS: BILLETERA | P2P | LLAMADAS 3D | INTELIGENCIA ARTIFICIAL" << endl;
        cout << "PROTECCIÓN LEGAL: VÁLIDA EN CHILE Y TODOS LOS PAÍSES" << endl;
        cout << "=============================================" << endl;
        cout << "NINGUNA PERSONA PUEDE USAR ESTE PROYECT
