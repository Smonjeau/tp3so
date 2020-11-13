# TP 3 SO Grupo 10

Clonar el repositorio en la carpeta deseada.

A continuación se presentan 2 alternativas de ejecución

## Compilación

Nos posicionamos dentro del repositorio clonado
```bash
cd tp3so
```
Ejecutamos el make que se encarga de compilar tanto el server como el client
```bash
make all
```
## A continuación se presentan 2 alternativas de ejecución

### Alternativa 1

Corremos el server por un lado (puede ser en una terminal separada o en la misma terminal en modo background).
```bash
server/server
```

Iniciamos el client. El script se encarga de llamar al ejecutable client y enviarle a su entrada estandar las respuestas que se leen del archivo respuestas.txt.

```bash
client/run_client.sh
```



### Alternativa 2

Corremos un único script que se encarga de iniciar el server en background y luego iniciar el client.
```bash
./run_all.sh
```
