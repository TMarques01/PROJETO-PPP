#include "projeto_header.h"

void menu_opcoes() {
    printf("\nInsira o numero correspondente a operacao que pretende realizar:\n"
           "\t\t\t1 : 'Adicionar reserva'\n"
           "\t\t\t2 : 'Eliminar reserva'\n"//fazer
           "\t\t\t3 : 'Eliminar pré-reserva'\n"//fazer
           "\t\t\t4 : 'Listar Reservas(por data)'\n"
           "\t\t\t5 : 'Listar Reservas(por cliente)'\n"//fazer
           "\t\t\t0 : 'Sair'\n"
           "Opcao: ");
}

int lista_vazia(Reserva lista) {
    if (lista->prox == NULL) return 1;
    else return 0;
}

void imprimir_reservas(Reserva lista) { //IMPRIME A LISTA DAS RESERVAS;
    if (lista_vazia(lista)) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("\n");
    printf("Reservas:\n");
    Reserva atual = lista->prox; //salta o header
    while (atual != NULL) {
        printf("Cliente: %s\n", atual->Cliente.nome);
        printf("Telemóvel: %ld\n", atual->Cliente.telemovel);
        if(atual->tipo_reserva==1){
            printf("Tipo de reserva: Lavagem\n");
        } else if(atual->tipo_reserva==0) {
            printf("Tipo de reserva: Manutenção\n");
        }
        printf("Data: %02d/%02d/%04d\n", atual->Data.dia, atual->Data.mes, atual->Data.ano);
        printf("Horário de início: %02d:%02d\n", atual->horas_inicio.horas, atual->horas_inicio.minutos);
        printf("Horário de fim: %02d:%02d\n", atual->horas_fim.horas, atual->horas_fim.minutos);
        printf("\n");
        atual = atual->prox;
    }
}

void imprimir__pre_reservas(Pre_reserva lista) { //IMPRIME A LISTA DAS RESERVAS;
    if (lista->prox==NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("\n");
    printf("Pré-reservas:\n");
    Pre_reserva atual = lista->prox; //salta o header
    while (atual != NULL) {
        printf("Cliente: %s\n", atual->pre_reservaa.Cliente.nome);
        printf("Telemóvel: %ld\n", atual->pre_reservaa.Cliente.telemovel);
        if(atual->pre_reservaa.tipo_reserva==1){
            printf("Tipo de reserva: Lavagem\n");
        } else if(atual->pre_reservaa.tipo_reserva==0) {
            printf("Tipo de reserva: Manutenção\n");
        }
        printf("Data: %02d/%02d/%04d\n", atual->pre_reservaa.Data.dia, atual->pre_reservaa.Data.mes, atual->pre_reservaa.Data.ano);
        printf("Horário de início: %02d:%02d\n", atual->pre_reservaa.horas_inicio.horas, atual->pre_reservaa.horas_inicio.minutos);
        printf("Horário de fim: %02d:%02d\n", atual->pre_reservaa.horas_fim.horas, atual->pre_reservaa.horas_fim.minutos);
        printf("\n");
        atual = atual->prox;
    }
}

//////////////////////////////////////////////////////////////////////////////////// 
//CRIAR AS LISTAS (reserva e pre_reserva)
//////////////////////////////////////////////////////////////////////////////////// 

Reserva criar_lista_reserva() {
    Reserva p = (Reserva) malloc(sizeof(reserva));
    if(p==NULL){
        perror("ERRO AO ALOCAR MEMÓRIA");
    }
    strcpy(p->Cliente.nome,"");
    p->Cliente.telemovel=0;
    p->Data.mes=0;
    p->Data.ano=0;
    p->Data.dia=0;
    p->tipo_reserva=-1;
    p->horas_inicio.horas=0;
    p->horas_inicio.minutos=0;
    p->horas_fim.minutos=0;
    p->horas_fim.horas=0;
    p->prox=NULL;

    Reserva header = (Reserva) malloc(sizeof(reserva));
    if (header == NULL) {
        printf("ERRO A ALOCAR MEMORIA\n");
        return NULL;
    }
    header=p;
    return header;
}

Pre_reserva criar_lista_pre_reserva() {
    Pre_reserva p = (Pre_reserva) malloc(sizeof(pre_reserva));
    if(p==NULL){
        perror("ERRO AO ALOCAR MEMÓRIA");
    }
    strcpy(p->pre_reservaa.Cliente.nome,"");
    p->pre_reservaa.Cliente.telemovel=0;    
    p->pre_reservaa.Data.mes=0;
    p->pre_reservaa.Data.ano=0;
    p->pre_reservaa.Data.dia=0;
    p->pre_reservaa.tipo_reserva=-1;
    p->pre_reservaa.horas_inicio.horas=0;
    p->pre_reservaa.horas_inicio.minutos=0;
    p->pre_reservaa.horas_fim.minutos=0;
    p->pre_reservaa.horas_fim.horas=0;
    p->pre_reservaa.prox=NULL;

    Pre_reserva header=p;
    return header;
}

int comparar_reservas(Reserva r1, Reserva r2) { //RETURN 1 SE A PRIMEIRA DATA FOR MAIS RECENTE RETURN -1 PARA O CONTRÁRIO
    if (r1->Data.ano < r2->Data.ano) {
        return -1;
    } else if (r1->Data.ano > r2->Data.ano) {
        return 1;
    } else {
        if (r1->Data.mes < r2->Data.mes) {
            return -1;
        } else if (r1->Data.mes > r2->Data.mes) {
            return 1;
        } else {
            if (r1->Data.dia < r2->Data.dia) {
                return -1;
            } else if (r1->Data.dia > r2->Data.dia) {
                return 1;
            } else {
                if (r1->horas_inicio.horas < r2->horas_inicio.horas) {
                    return -1;
                } else if (r1->horas_inicio.horas > r2->horas_inicio.horas) {
                    return 1;
                } else {
                    if (r1->horas_inicio.minutos < r2->horas_inicio.minutos) {
                        return -1;
                    } else if (r1->horas_inicio.minutos > r2->horas_inicio.minutos) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}

int comparar_pre_reservas(Pre_reserva r1, Reserva r2) { //RETURN 1 SE A PRIMEIRA DATA FOR MAIS RECENTE RETURN -1 PARA O CONTRÁRIO
    if (r1->pre_reservaa.Data.ano < r2->Data.ano) {
        return -1;
    } else if (r1->pre_reservaa.Data.ano > r2->Data.ano) {
        return 1;
    } else {
        if (r1->pre_reservaa.Data.mes < r2->Data.mes) {
            return -1;
        } else if (r1->pre_reservaa.Data.mes > r2->Data.mes) {
            return 1;
        } else {
            if (r1->pre_reservaa.Data.dia < r2->Data.dia) {
                return -1;
            } else if (r1->pre_reservaa.Data.dia > r2->Data.dia) {
                return 1;
            } else {
                if (r1->pre_reservaa.horas_inicio.horas < r2->horas_inicio.horas) {
                    return -1;
                } else if (r1->pre_reservaa.horas_inicio.horas > r2->horas_inicio.horas) {
                    return 1;
                } else {
                    if (r1->pre_reservaa.horas_inicio.minutos < r2->horas_inicio.minutos) {
                        return -1;
                    } else if (r1->pre_reservaa.horas_inicio.minutos > r2->horas_inicio.minutos) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////// 
//FUNÇÕES PARA A HORA_FIM (VERIFICAR SE ENCONTRA DENTRO DO HORARIO DE TRABALHO)
//////////////////////////////////////////////////////////////////////////////////// 

bool verificar_horario_fora_do_trabalho(struct horas *horas_fim, struct horas *horas_inicio){ //VERIFICA SE OS HORARIOS CORRESPONDENTES SE ENCONTRAM DENTRO DO HORARIO DE TRABALHO
    if((horas_fim->horas>18) || (horas_fim->horas==18 && horas_fim->minutos>0) || (horas_inicio->horas<8)){ //08h00 - 18h00
        return true;
    }
    return false;
}

struct horas *definir_hora_fim(int tipo_reserva, struct horas horas_inicio){ //FUNÇÃO PARA DEFINIR A HORA QUE ACABA A TAREFA
    struct horas *hora_fim=malloc(sizeof(struct horas));
    if(hora_fim==NULL){
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    if (tipo_reserva==1){ //CASO SEJA LAVAGEM
        if(horas_inicio.minutos==30){
            hora_fim->minutos=0;
            hora_fim->horas=horas_inicio.horas+1;
        } else {
            hora_fim->horas=horas_inicio.horas;
            hora_fim->minutos=30;
        }
    } else if (tipo_reserva==0) { //CASO SEJA MANUTENÇÃO
        hora_fim->horas=horas_inicio.horas+1;
        hora_fim->minutos=horas_inicio.minutos;
    }

    if(verificar_horario_fora_do_trabalho(hora_fim,&horas_inicio)){ //VERIFICA SE A HORA DO FIM NÃO SAI DO HORARIO DE TRABALHO 08h00 - 18h00
        printf("Não é possivel adicionar hora.\n");
        exit(1);
    }
    return hora_fim;
}

//////////////////////////////////////////////////////////////////////////////////// 
//CRIAR OS CLIENTES
//////////////////////////////////////////////////////////////////////////////////// 

struct cliente *criar_cliente(char *nome,int telemovel){ //CRIA O CLIENTE
    struct cliente *c=malloc(sizeof(struct cliente));

    if(c==NULL){
        printf("ERRO A ALOCAR MEMORIA\n");
    }

    int id;

    strcpy(c->nome,nome);
    c->telemovel=telemovel;

    return c;
}

struct reserva *criar_reserva(){ //CRIA A RESERVA
    struct reserva *c=malloc(sizeof(reserva));
    struct horas hora_inicio;
    struct horas hora_fim;
    struct data Data_temp;
    char nome[100];
    char data[11];
    int tipo_reserva;
    long telemovel;
    
    printf("NOME: ");
    scanf("%s",nome);

    printf("TELEMOVEL: ");
    scanf("%ld",&telemovel);

    strcpy(c->Cliente.nome,criar_cliente(nome,telemovel)->nome);
    c->Cliente.telemovel=criar_cliente(nome,telemovel)->telemovel;

    printf("TIPO DE RESERVA (0 = MANUTENÇÃO || 1 = LAVAGEM): ");
    scanf("%d",&tipo_reserva);

    printf("HORAS: ");
    scanf("%d",&(hora_inicio.horas));

    printf("MINUTOS: ");
    scanf("%d",&(hora_inicio.minutos)); 

    c->horas_fim.horas=definir_hora_fim(tipo_reserva,hora_inicio)->horas;
    c->horas_fim.minutos=definir_hora_fim(tipo_reserva,hora_inicio)->minutos;

    printf("DATA (DD/MM/AAAA): ");
    printf("DIA: ");
    scanf("%d",&Data_temp.dia);
    printf("MES: ");
    scanf("%d",&Data_temp.mes);
    printf("ANO: ");
    scanf("%d",&Data_temp.ano);

    c->Data.dia=Data_temp.dia;
    c->Data.mes=Data_temp.mes;
    c->Data.ano=Data_temp.ano;
    c->tipo_reserva=tipo_reserva;
    c->horas_inicio=hora_inicio;
    c->prox=NULL;

    return c;
}

//////////////////////////////////////////////////////////////////////////////////// 
//NA PRIMEIRA FUNÇÃO APENAS ADICIONA O PRIMEIRO ELEMENTO À LISTA
//NA SEGUNDA, JÁ COMEÇA A COMPARAR E A ADICIONAR POR DATA
//AINDA NÃO SEI SE ESTA A ADICIONAR TUDO DIREITINHO E SE A FUNÇÃO QUE VERIFICA SE A HORA ESTA DISPONIVEL ESTA A FUNCIONAR NESTE CASO
//////////////////////////////////////////////////////////////////////////////////// 

void adicionar_reserva_vazia_a_lista(Reserva cabeca, Reserva nova){ //ADICIONAR À LISTA, A RESERVA (não estou a usar)
    Reserva atual=cabeca;
    Reserva nova_reserva=nova;

    // Percorre a lista até encontrar o último nó
    while(atual->prox!=NULL){
        atual=atual->prox;
    }

    nova_reserva->prox=atual->prox;
    atual->prox=nova_reserva;
}

void adicionar_reserva_a_lista_teste(Reserva cabeca, Reserva nova) {
    Reserva anterior = cabeca;
    Reserva atual = anterior->prox;

    // Percorre a lista enquanto a data e hora da reserva atual forem menores que a da nova reserva
    while (atual != NULL && (comparar_reservas(atual,nova)==-1)){
        anterior = atual;
        atual = atual->prox;
    }

    // Insere o novo nó na lista na posição encontrada
    nova->prox = atual;
    anterior->prox = nova;
}


void remover_reserva(Reserva cabeca, long telemovel_cliente) { //REMOVE CLIENTE DA LISTA DANDO O N DE TELEMOVEL DO MESMO
    Reserva atual = cabeca->prox; // começa no primeiro nó (após o nó cabeça)
    Reserva anterior = cabeca;


    // Percorre a lista até encontrar o nó a ser eliminado
    while (atual != NULL) {
        if (atual->Cliente.telemovel == telemovel_cliente) {
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Caso o nó a ser eliminado seja encontrado
    if (atual != NULL) {
        anterior->prox = atual->prox;
        free(atual);
    } else {
        printf("Reserva não encontrada.\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////// 
//FUNÇÕES PARA VERIFICAR SE HÁ HORAS DISPONIVIES (A SEGUNDA AINDA ESTÁ MEIO INSTÁVEL)
///////////////////////////////////////////////////////////////////////////////////// 

bool horario_disponivel(Reserva cabeca, Reserva temporario, Reserva anterior){
    Reserva atual = cabeca;
    Reserva temp = temporario;
    Reserva ant = anterior;

    if ((atual->Data.ano == temp->Data.ano) && (atual->Data.mes == temp->Data.mes) && (atual->Data.dia == temp->Data.dia)) {   //VERIFICA SE O HORARIO DO INCIO É IGUAL
        if ((atual->horas_inicio.horas == temp->horas_inicio.horas) && (atual->horas_inicio.minutos == temp->horas_inicio.minutos)) {
            return true;
        }
        
        if(atual->tipo_reserva==0){
            if((atual->horas_inicio.horas==temp->horas_inicio.horas && atual->horas_fim.horas>temp->horas_inicio.horas)){ 
                return true; //EXEMPLO 16h00 - 17h00 e quer uma reserva às 16h30 (não pode)
            } else if((atual->horas_inicio.horas<temp->horas_inicio.horas) && (atual->horas_fim.horas==temp->horas_inicio.horas) && (atual->horas_fim.minutos>temp->horas_inicio.minutos)){
                return true; //EXEMPLO 16h30 - 17h30 e quer uma reserva às 17h00 (não pode)
            }
        }

        if(temp->tipo_reserva==0){
            printf("ENTROU\n");
            printf("%s\n",ant->Cliente.nome);
            if(ant->horas_fim.horas==temp->horas_inicio.horas && ant->horas_fim.minutos==temp->horas_inicio.minutos) {
                printf("ENTROU NO IF \n");
                if((atual->horas_inicio.horas==temp->horas_fim.horas) && (atual->horas_inicio.minutos<temp->horas_fim.minutos)) return true;
                if((atual->horas_inicio.horas<temp->horas_fim.horas)&&(atual->horas_inicio.minutos>temp->horas_fim.minutos)) return true;
            }
        }
    }
    return false;
}

bool existe_hora_preenchida_teste(Reserva cabeca, Reserva temporario) {
    Reserva atual = cabeca;
    Reserva temp = temporario;
    Reserva ant = NULL; 

    // Verifica se a lista não está vazia
    if (atual != NULL) {
        // Verifica se o primeiro elemento é igual ao temporario
        if (atual->Cliente.telemovel != temp->Cliente.telemovel) {
            if (horario_disponivel(atual,temp,ant)) return true;
        }

        // Percorre a lista a partir do segundo elemento
        while (atual->prox != NULL) {
            ant=atual;
            atual = atual->prox;
            if (atual->Cliente.telemovel != temp->Cliente.telemovel) {
                if (horario_disponivel(atual,temp,ant)) return true;
            }
        }
    }
    return false;
}

bool verifica_horas_teste(Reserva cabeca, Reserva reserva) { //NÃO ESTOU A USAR
    Reserva atual=cabeca;
    Reserva temp=reserva;

    int reserva_horas = reserva->horas_inicio.horas;
    int reserva_minutos = reserva->horas_inicio.minutos;

    //if(existe_hora_preenchida(cabeca,reserva)) return true;

    while(atual != NULL) {
        int atual_horas = atual->horas_fim.horas;
        int atual_minutos = atual->horas_fim.minutos;
        if((atual->Data.ano==temp->Data.ano) && (atual->Data.mes==temp->Data.mes) && (atual->Data.dia==temp->Data.dia)){
            if(temp->tipo_reserva == atual->tipo_reserva) {
                if(reserva_horas == atual_horas && reserva_minutos == atual_minutos) {
                    return true;
                }
                if((abs(reserva_horas - atual_horas) == 1 && reserva_minutos == atual_minutos && atual->tipo_reserva == 1) || 
                (abs(reserva_horas - atual_horas) == 1 && reserva_minutos == atual_minutos + 30 && atual->tipo_reserva == 0)) {
                    return true;
                }
            }
        }
        atual = atual->prox;
    }


    return false;
}

///////////////////////////////////////////////////////////////////////////////////// 
//ADICIONAR À PRE_RESERVA
///////////////////////////////////////////////////////////////////////////////////// 

void adicionar_pre_reserva_a_lista(Pre_reserva cabeca_pre_reserva, Pre_reserva nova) { //ADICIONA UM NÓ À LISTA DAS PRE RESERVAS (não está a funcionar)
    Pre_reserva anterior = cabeca_pre_reserva;
    Pre_reserva atual = anterior->prox;

    // Percorre a lista enquanto a data e hora da reserva atual forem menores que a da nova reserva
    while (atual != NULL && (comparar_pre_reservas(atual,nova)==-1)){
        anterior = atual;
        atual = atual->prox;
    }

    // Insere o novo nó na lista na posição encontrada
    nova->prox = atual;
    anterior->prox = nova;
}

///////////////////////////////////////////////////////////////////////////////////// 
//MAIN
///////////////////////////////////////////////////////////////////////////////////// 

int main(){
    Reserva r=criar_lista_reserva();
    Pre_reserva p=criar_lista_pre_reserva();

/*
    Reserva d=criar_reserva();
    adicionar_reserva_vazia_a_lista(p,d);
    if(verifica_horas(p,d)){
        printf("NÃO FOI POSSIVEL ADICIONAR A RESERVA\n");
        remover_reserva(p,d->Cliente.telemovel);
    } else {
        printf("Reserva adicionada com sucesso.\n");
    }
*/

    //TESTAR COM DUAS RESERVAS
    for(int i=0;i<3;i++){
        Reserva c=criar_reserva();
        adicionar_reserva_a_lista_teste(r,c);
        if(existe_hora_preenchida_teste(r,c)){                               
            printf("Não foi possivel adicionar a reserva\n"); 
            //adicionar_pre_reserva_a_lista(p,c); //ADICIONA À PRE_RESERVA                
            remover_reserva(r,c->Cliente.telemovel); //ELIMINA DA LISTA DAS RESERVAS
        } else {
            printf("Reserva adicionada com sucesso.\n");
        }   
    }
    imprimir_reservas(r);
    //imprimir__pre_reservas(p);
    return 0;
}

//DENTRO DA VERIFICAÇÃO AINDA TEM ALGUMAS CENAS, FAZER A FUNÇAO PROCURA PARA VER ELEMENTOS
