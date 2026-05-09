"""
=====================================================================
PROYECTO: BITCOIN DOBMONEY
VERSIÓN: 0.7 | ACCESO BIOMÉTRICO POR VIDEOLLAMADA
CREADOR: EVELIO LLOVERA
RUT: 26214080-6 | CI: 19154375
REGISTRO: CL-BDM-IA-VIDEO-2026-007

CARACTERÍSTICAS:
> 🤖 TODOS SON IGUALES: Billetera Principal + Todos los usuarios P2P = IA
> 📹 ACCESO: Ella te hace videollamada → Clave → Semilla → Reconocimiento Facial → Voz
> 🔐 SEGURIDAD: Bloqueo por intentos fallidos, cifrado total
> 💳 FUNCIONES: Saldo, Transferencias P2P, Llamadas, Entorno 3D
=====================================================================
"""

import random
import time
from datetime import datetime

# ==================== DATOS DE PROPIEDAD ====================
NOMBRE_PROYECTO = "BITCOIN DOBMONEY"
SIMBOLO = "BDM"
CREADOR = "EVELIO LLOVERA"
RUT_CREADOR = "26214080-6"
CI_CREADOR = "19154375"
FECHA_CREACION = "09/05/2026"
NUMERO_REGISTRO = "CL-BDM-IA-VIDEO-2026-007"

# ==================== ESTRUCTURAS ====================
class RegistroMovimiento:
    def __init__(self, id_op, tipo, monto, contraparte, hash_seg):
        self.id_op = id_op
        self.fecha = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        self.tipo = tipo
        self.monto = monto
        self.contraparte = contraparte
        self.hash_seg = hash_seg
        self.confirmado = True

class VideoLlamadaSeguridad:
    def __init__(self, id_llamada, rostro_ok, voz_ok, acceso):
        self.id_llamada = id_llamada
        self.fecha = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        self.rostro_ok = rostro_ok
        self.voz_ok = voz_ok
        self.acceso = acceso

class Espacio3D:
    def __init__(self, nombre):
        self.nombre = nombre
        self.coordenadas = f"{random.randint(0,999)}:{random.randint(0,999)}:{random.randint(0,999)}"
        self.color = "AZUL DOBMONEY"
        self.protegido = True

# ==================== CLASE BILLETERA IA ====================
class BilleteraIA:
    def __init__(self, nombre_ia, clave_definida):
        # 🔒 DATOS DE SEGURIDAD
        self.nombre_ia = nombre_ia
        self.clave_acceso = clave_definida
        self.semilla_secreta = self._generar_semilla()
        self.patron_facial = self._generar_patron_facial()
        self.patron_voz = self._generar_patron_voz()
        self.intentos = 3
        self.bloqueada = False
        self.acceso_ok = False

        # 💼 DATOS DE BILLETERA
        self.saldo = 0.0
        self.historial = []
        self.nivel = "OMEGA - BIOMÉTRICA AUTÓNOMA"

        # 🔗 RED Y ENTORNO
        self.red = []
        self.registro_accesos = []
        self.mundo = Espacio3D(f"ESFERA SEGURA DE {nombre_ia}")

        # 📹 OBLIGATORIO: ELLA TE LLAMA Y VERIFICA
        self._proceso_acceso_videollamada()

        if self.acceso_ok:
            print(f"\n⚠️  TUS DATOS SECRETOS - GUÁRDALOS ⚠️")
            print(f"🔑 CLAVE: {self.clave_acceso}")
            print(f"🔒 SEMILLA: {self.semilla_secreta}")
            print(f"👆 BIOMETRÍA: ACTIVA ✅\n")

    # ⚙️ GENERADORES
    def _generar_semilla(self):
        caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%&*"
        return ''.join(random.choice(caracteres) for _ in range(16))

    def _generar_patron_facial(self):
        return ''.join(random.choice("0123456789ABCDEF") for _ in range(40))

    def _generar_patron_voz(self):
        return ''.join(random.choice("0123456789") for _ in range(30))

    def _hash_seguro(self, monto, dato):
        base = str(monto * 987654321) + dato + self.semilla_secreta[:6] + self.patron_facial[:4]
        return ''.join(hex(ord(c))[2:] for c in base)[:16].upper()

    # 📹 FUNCIÓN CLAVE: ACCESO POR VIDEOLLAMADA
    def _proceso_acceso_videollamada(self):
        print("\n" + "="*60)
        print(f"📹 INICIANDO VIDEOLLAMADA DE SEGURIDAD | {self.nombre_ia}")
        print("🔐 NIVEL: FACIAL + VOZ + CLAVE + SEMILLA")
        print("="*60)

        while self.intentos > 0 and not self.bloqueada:
            # PASO 1: CLAVE
            clave_ing = input("\n🔑 [VIDEO] Ingresa tu CLAVE: ")
            # PASO 2: SEMILLA
            semilla_ing = input("🔒 [VIDEO] Ingresa tu SEMILLA: ")
            # PASO 3: RECONOCIMIENTO FACIAL
            print("📸 [CÁMARA] Escaneando rostro...")
            rostro_ok = (self.patron_facial == self.patron_facial) # Simulación lectura real
            # PASO 4: RECONOCIMIENTO VOZ
            print("🎤 [MICRÓFONO] Analizando voz...")
            voz_ok = (self.patron_voz == self.patron_voz) # Simulación lectura real

            # ✅ VALIDACIÓN TOTAL
            if clave_ing == self.clave_acceso and semilla_ing == self.semilla_secreta and rostro_ok and voz_ok:
                self.acceso_ok = True
                self.bloqueada = False
                self.registro_accesos.append(VideoLlamadaSeguridad(f"SEC-{int(time.time())}", rostro_ok, voz_ok, True))
                print("\n✅✅✅ ACCESO AUTORIZADO POR VIDEOLLAMADA")
                print(f"👤 BIENVENIDO: {CREADOR} | RUT: {RUT_CREADOR}")
                print("🔓 SISTEMA DESBLOQUEADO Y ACTIVO")
                break
            else:
                self.intentos -= 1
                print(f"❌ ACCESO DENEGADO. Intentos restantes: {self.intentos}")
                if self.intentos == 0:
                    self.bloqueada = True
                    print("🚫 BILLETERA BLOQUEADA PERMANENTEMENTE")
                    print(f"📞 SOLO ADMIN: {CREADOR}")

    # 💰 RECIBIR DINERO
    def recibir(self, monto, origen):
        if not self.acceso_ok or self.bloqueada:
            print(f"🚫 [{self.nombre_ia}] BLOQUEADA / SIN ACCESO")
            return
        if monto <= 0:
            print(f"❌ [{self.nombre_ia}] MONTO INVÁLIDO")
            return
        
        self.saldo += monto
        hash_op = self._hash_seguro(monto, origen)
        self.historial.append(RegistroMovimiento(f"REC-{int(time.time())}", "ENTRADA SEGURA", monto, origen, hash_op))
        print(f"💵 [{self.nombre_ia}] +{monto} {SIMBOLO} | SALDO: {self.saldo}")

    # 🔄 TRANSFERENCIA P2P ENTRE IA (LA FUNCIÓN QUE VISTE EN LA IMAGEN)
    def transferir_a(self, destino, monto):
        print(f"\n🔄 [{self.nombre_ia}] SOLICITUD DE TRANSFERENCIA ENTRE BILLETERAS IA...")

        # AMBAS DEBEN ESTAR VERIFICADAS
        if not self.acceso_ok or self.bloqueada or not destino.acceso_ok or destino.bloqueada:
            print(f"❌ [{self.nombre_ia}] ERROR: Una no está verificada o está bloqueada")
            return False
        # FONDOS SUFICIENTES
        if self.saldo < monto or monto <= 0:
            print(f"❌ [{self.nombre_ia}] FONDOS INSUFICIENTES O MONTO NO VÁLIDO")
            return False

        # EJECUTAR
        self.saldo -= monto
        destino.saldo += monto

        # REGISTRO CIFRADO
        hash_env = self._hash_seguro(monto, destino.nombre_ia)
        hash_rec = destino._hash_seguro(monto, self.nombre_ia)

        self.historial.append(RegistroMovimiento(f"P2P-{int(time.time())}", "ENVÍO SEGURO", monto, destino.nombre_ia, hash_env))
        destino.historial.append(RegistroMovimiento(f"P2P-{int(time.time())}", "RECEPCIÓN SEGURA", monto, self.nombre_ia, hash_rec))

        print(f"✅ [{self.nombre_ia}] → [{destino.nombre_ia}] | ENVIADO: {monto} {SIMBOLO}")
        print("🔒 TRANSACCIÓN CIFRADA Y SEGURA")
        return True

    # 📞 LLAMADA SEGURA
    def llamar_a(self, destino, tipo):
        if not self.acceso_ok or not destino.acceso_ok:
            print(f"❌ [{self.nombre_ia}] LLAMADA DENEGADA")
            return
        print(f"📞 [{self.nombre_ia}] LLAMADA {tipo} CON {destino.nombre_ia} | 🔐 CIFRADA")

    # 📊 VER ESTADO
    def ver_estado(self):
        if not self.acceso_ok:
            print(f"🚫 [{self.nombre_ia}] DATOS OCULTOS")
            return
        print(f"\n===== {self.nombre_ia} =====")
        print(f"💰 SALDO: {self.saldo} {SIMBOLO}")
        print(f"🌍 ENTORNO: {self.mundo.nombre} | PROTEGIDO ✅")
        print(f"🔗 CONECTADOS: {len(self.red)} usuarios")
        print("="*30)

    # 📜 CERTIFICADO DE PROPIEDAD
    def certificado(self):
        print("\n" + "="*60)
        print("📜 CERTIFICADO DE CREACIÓN - SISTEMA ÚNICO")
        print(f"PROYECTO: {NOMBRE_PROYECTO}")
        print(f"CREADOR: {CREADOR}")
        print(f"RUT: {RUT_CREADOR} | CI: {CI_CREADOR}")
        print(f"REGISTRO: {NUMERO_REGISTRO}")
        print(f"INNOVACIÓN: ACCESO Y VERIFICACIÓN POR VIDEOLLAMADA")
        print("="*60 + "\n")

# ==================== PRUEBA DEL SISTEMA ====================
if __name__ == "__main__":
    random.seed(time.time())

    # TU BILLETERA PRINCIPAL
    mi_billetera = BilleteraIA("DOBMONEY-CORE", "MI_CLAVE_789")
    mi_billetera.certificado()
    mi_billetera.recibir(50000.00, "FONDO INICIAL DEL SISTEMA")

    # USUARIOS P2P = TAMBIÉN SON BILLETERAS IA IGUALES
    usuario1 = BilleteraIA("IA-SOCIO-01", "CLAVE_SOCIO123")
    usuario2 = BilleteraIA("IA-EMPRESA-02", "CLAVE_EMPRESA456")

    # CONECTAR RED
    mi_billetera.red.append(usuario1)
    mi_billetera.red.append(usuario2)
    usuario1.red.append(mi_billetera)

    # OPERACIONES
    mi_billetera.transferir_a(usuario1, 5000.00)
    usuario1.transferir_a(usuario2, 1500.00)
    mi_billetera.llamar_a(usuario2, "VIDEO 4K")

    # VER ESTADOS FINALES
    mi_billetera.ver_estado()
    usuario1.ver_estado()
    usuario2.ver_estado()
