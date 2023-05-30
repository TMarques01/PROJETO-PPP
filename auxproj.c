#include "projeto_header.h"

int lista_vazia(Reserva lista) {
    if (lista->prox == NULL) return 1;
    else return 0;
}

//////////////////////////////////////////////////////////////////////////////////// 
//IMPRIMIR POR DATA AS LISTAS (reserva e pre_reserva)
//////////////////////////////////////////////////////////////////////////////////// 

void imprimir_reservas(Reserva lista) { //IMPRIME A LISTA DAS RESERVAS POR DATA;
    if (lista_vazia(lista)) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("\n");
    printf("Reservas:\n");
    printf("\n");
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

void imprimir_pre_reservas(Pre_reserva lista) { //IMPRIME A LISTA DAS RESERVAS POR DATA;
    if (lista->prox==NULL) {
        printf("A lista das pré-reserva está vazia.\n");
        return;
    }
    printf("\n");
    printf("Pré-reservas:\n");
    printf("\n");
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

void imprimir_cliente(L_cliente lista) { //IMPRIME A LISTA DAS RESERVAS POR DATA;
    if (lista->prox==NULL) {
        printf("A lista do cliente está vazia.\n");
        return;
    }
    printf("\n");
    L_cliente atual = lista->prox; //salta o header
    printf("Cliente: %s\n", atual->ord_cliente.Cliente.nome);
    printf("Telemóvel: %ld\n", atual->ord_cliente.Cliente.telemovel);


    while (atual != NULL) {
        printf("Pertence à lista das: %s\n",atual->lista);
        if(atual->ord_cliente.tipo_reserva==1){
            printf("Tipo de reserva: Lavagem\n");
        } else if(atual->ord_cliente.tipo_reserva==0) {
            printf("Tipo de reserva: Manutenção\n");
        }
        printf("Data: %02d/%02d/%04d\n", atual->ord_cliente.Data.dia, atual->ord_cliente.Data.mes, atual->ord_cliente.Data.ano);
        printf("Horário de início: %02d:%02d\n", atual->ord_cliente.horas_inicio.horas, atual->ord_cliente.horas_inicio.minutos);
        printf("Horário de fim: %02d:%02d\n", atual->ord_cliente.horas_fim.horas, atual->ord_cliente.horas_fim.minutos);
        printf("\n");
        atual = atual->prox;
    }
}

//////////////////////////////////////////////////////////////////////////////////// 
//CRIAR AS LISTAS (reserva e pre_reserva)
//////////////////////////////////////////////////////////////////////////////////// 

Reserva criar_lista_reserva() { //CRIA LISTA DAS RESERVAS
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

Pre_reserva criar_lista_pre_reserva() { //CRIA LISTA DAS PRE_RESERVAS
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

L_cliente criar_lista_l_cliente() { //CRIA LISTA DO CLIENTE (lista feita para imprimir as reservas e pré_reservas dum cliente)
    L_cliente p = (L_cliente) malloc(sizeof(l_cliente));
    if(p==NULL){
        perror("ERRO AO ALOCAR MEMÓRIA");
    }
    strcpy(p->ord_cliente.Cliente.nome,"");
    strcpy(p->lista,"");
    p->ord_cliente.Cliente.telemovel=0;    
    p->ord_cliente.Data.mes=0;
    p->ord_cliente.Data.ano=0;
    p->ord_cliente.Data.dia=0;
    p->ord_cliente.tipo_reserva=-1;
    p->ord_cliente.horas_inicio.horas=0;
    p->ord_cliente.horas_inicio.minutos=0;
    p->ord_cliente.horas_fim.minutos=0;
    p->ord_cliente.horas_fim.horas=0;
    p->ord_cliente.prox=NULL;

    L_cliente header=p;
    return header;
}

//////////////////////////////////////////////////////////////////////////////////// 
//FUNÇÕES PARA COMPARAR DATA E HORAS
////////////////////////////////////////////////////////////////////////////////////

int comparar_reservas_cliente(struct data d1,struct data d2, struct horas h1, struct horas h2) { //RETURN 1 SE A PRIMEIRA DATA FOR MAIS RECENTE RETURN -1 PARA O CONTRÁRIO
    if (d1.ano < d2.ano){                                      //estas são as horas iniicio
        return -1;
    } else if (d1.ano > d2.ano) {
        return 1;
    } else {
        if (d1.mes < d2.mes) {
            return -1;
        } else if (d1.mes > d2.mes) {
            return 1;
        } else {
            if (d1.dia < d2.dia) {
                return -1;
            } else if (d1.dia > d2.dia) {
                return 1;
            } else {
                if (h1.horas < h2.horas) {
                    return -1;
                } else if (h1.horas > h2.horas) {
                    return 1;
                } else {
                    if (h1.minutos < h2.minutos) {
                        return -1;
                    } else if (h1.minutos > h2.minutos) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}

int compara_datas(struct data d1,struct data d2) {
    if(d1.ano<d2.ano)
        return -1;

    if(d1.ano>d2.ano)
        return 1;

    else{
        if(d1.mes<d2.mes)
            return -1;
        if(d1.mes>d2.mes)
            return 1;
        else{
            if(d1.dia<d2.dia)
                return -1;
            if(d1.dia>d2.dia)
                return 1;
            else
                return 0;
        }
    }
}

int compara_horas(struct horas h1, struct horas h2) {
    if (h1.horas < h2.horas) 
        return -1;
    if (h1.horas > h2.horas) 
        return 1;
    
    else {
        if (h1.minutos < h2.minutos) 
            return -1;
        
        if (h1.minutos > h2.minutos) 
            return 1;
        
        else  
            return 0;
        
    }
}

//////////////////////////////////////////////////////////////////////////////////// 
//FUNÇÕES DE VERIFICAÇÃO (VERIFICAR SE ENCONTRA DENTRO DO HORARIO DE TRABALHO)
//////////////////////////////////////////////////////////////////////////////////// 

bool dataValida(struct data Data) { //VERIFICA SE A DATA É VÁLIDA
    if (Data.mes < 1 || Data.mes > 12){ //sai fora dos meses
        printf("Data inválida.\n");
        return true;
    } 
    if (Data.mes == 2) { //mes de fevereiro
        if ((Data.ano % 4 == 0 && Data.ano % 100 != 0) || Data.ano % 400 == 0){
            if (Data.dia > 29){ // ano bissexto
                printf("Data inválida.\n");
                return true;
            } else if (Data.dia > 28){
                printf("Data inválida.\n");
                return true;
            };
        }
    } else if ((Data.mes == 4 || Data.mes == 6 || Data.mes == 9 || Data.mes == 11) && (Data.dia > 30)){ //meses em vai ate 30 dias
        printf("Data inválida.\n");
        return true;
    } else {
        if(Data.dia > 31){ //os outros meses
            printf("Data inválida.\n");
            return true;
        } 
    }
    return false;
}

bool verificar_horario_fora_do_trabalho(struct horas *horas_fim, struct horas *horas_inicio){ //VERIFICA SE OS HORARIOS CORRESPONDENTES SE ENCONTRAM DENTRO DO HORARIO DE TRABALHO
    if((horas_fim->horas>18) || (horas_fim->horas==18 && horas_fim->minutos>0) || (horas_inicio->horas<8) //08h00 - 18h00
    || (horas_inicio->horas>18)){ 
        return true;
    }
    return false;
}

bool verificar_n_telemovel_igual(Reserva cabeca, Pre_reserva p, long telemovel,char nome[]){ //VERIFICA SE O CLIENTE JÁ EXISTE NAS RESERVAS
    Reserva atual=cabeca;
    Pre_reserva atual_p=p;
    while(atual!=NULL){
        if((atual_p->pre_reservaa.Cliente.telemovel!=telemovel) && (strcmp(atual_p->pre_reservaa.Cliente.nome,nome)!=0)){ //para não comparar consigo mesmo
            if((atual->Cliente.telemovel==telemovel) && (strcmp(atual->Cliente.nome,nome)!=0)) //VERIFICA SE O TELEMOVEL É IGUAL 
            {                                                                                  //E O NOME É DIFERENTE
                printf("Número de telemóvel já existente (nas reservas).\n");
                return true;
            } 
        }
        atual=atual->prox;
    }
    //NÃO ESTÁ A ENTRAR
    while(atual_p!=NULL){
        if((atual_p->pre_reservaa.Cliente.telemovel!=telemovel) && (strcmp(atual_p->pre_reservaa.Cliente.nome,nome)!=0)){
            if((atual_p->pre_reservaa.Cliente.telemovel==telemovel) && (strcmp(atual_p->pre_reservaa.Cliente.nome,nome)!=0)){
                printf("Número de telemóvel já existente (nas pré-reservas).\n");
                return true;
            }
        }
        atual_p=atual_p->prox;
    }
    return false;
}

//FUNÇÕES PARA VERIFICAR SE HÁ HORAS DISPONIVIES

bool horario_disponivel(Reserva cabeca, Reserva temporario){
    Reserva atual = cabeca;
    Reserva temp = temporario;

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
        if (compara_horas(atual->horas_inicio, temp->horas_fim) == -1 && compara_horas(atual->horas_fim, temp->horas_inicio) == 1) { // verificar se há sobreposição de horários
            return true; // não é possível marcar
        }
        if (atual->tipo_reserva == 0) { // se for uma manutenção(1hora)
            if (compara_horas(atual->horas_inicio, temp->horas_inicio) == 0 && compara_horas(atual->horas_fim, temp->horas_fim) == 0) {
                return true; // não é possível marcar
            }
            if (compara_horas(atual->horas_inicio, temp->horas_inicio) == -1 && compara_horas(atual->horas_fim, temp->horas_inicio) == 1) {
                return true; // não é possível marcar
            }
            if (compara_horas(atual->horas_inicio, temp->horas_fim) == -1 && compara_horas(atual->horas_fim, temp->horas_fim) == 1) {
                return true; // não é possível marcar
            }
        }
    }
    return false;
}

bool existe_hora_preenchida(Reserva cabeca, Reserva temporario) { //VERIFICA SE O HORARIO É DISPONIVEL COM TODOS OS ELEMENTOS DA LISTA
    Reserva atual = cabeca;
    Reserva temp = temporario;

    // Verifica se a lista não está vazia
    if (atual != NULL) {
        // Verifica se o primeiro elemento é igual ao temporario
        if (atual->Cliente.telemovel != temp->Cliente.telemovel) {
            if (horario_disponivel(atual,temp)) return true;
        }

        // Percorre a lista a partir do segundo elemento
        while (atual->prox != NULL) {
            atual = atual->prox;
            if (atual->Cliente.telemovel != temp->Cliente.telemovel) {
                if (horario_disponivel(atual,temp)) return true;
            }
        }
    }
    return false;
}

bool bloco_de_hora_valido(int minutos){ //verifica se os minutos da hora estão corretos, visto os serviços são feitos de meia em meia hora
    if(minutos == 0 || minutos == 30) {
        return false;
    }
    return true;
}

bool verificar_se_n_telemovel_tem_caracter(char telemovel[]){ // verifica se o numero de telemovel tem caracter
    for(int i=0;i<strlen(telemovel);i++){
        if(!isdigit(telemovel[i])){
            return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////////////// 
//CRIAR OS CLIENTES
//////////////////////////////////////////////////////////////////////////////////// 

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

    return hora_fim;
}

struct reserva *criar_reserva(Reserva r, Pre_reserva p){ //CRIA A RESERVA
    struct reserva *c=malloc(sizeof(reserva));
    struct horas hora_inicio;
    struct horas hora_fim;
    struct data Data_temp;
    char nome[100];
    char n_telemovel[100];
    int tipo_reserva,result,i;
    long telemovel;
    
    printf("NOME (Digite sem espaços): "); //nome do cliente
    scanf("%s",nome);
    
    printf("TELEMÓVEL: "); //nº telemovel
    scanf("%s",n_telemovel);

    while(verificar_se_n_telemovel_tem_caracter(n_telemovel)){
        printf("Numero de telemóvel contem caracter inválido.\n");
        printf("Digite novamente: ");
        scanf("%s",n_telemovel);
    }

    telemovel=atol(n_telemovel);

    while(verificar_n_telemovel_igual(r,p,telemovel,nome)){
        printf("Digite um valor válido: ");
        scanf("%ld",&telemovel);
    }

    printf("TIPO DE RESERVA (0 = MANUTENÇÃO || 1 = LAVAGEM): "); //tipo de reserva
    scanf("%d",&tipo_reserva);

    while(tipo_reserva!=0 && tipo_reserva!= 1){ //verifica se o valor é o correto
        printf("Valor inválido!\n");
        printf("Digite outro valor: ");
        scanf("%d",&tipo_reserva);
    }

    printf("HORAS (HH:MM): ");
    scanf("%d:%d",&(hora_inicio.horas),&(hora_inicio.minutos));
    
    while(bloco_de_hora_valido(hora_inicio.minutos)) { //verificar se as horas estão em blocos de meia hora
        printf("Hora inválida.\n");
        printf("Digite um valor válido (horas devem estar em blocos de meia hora): ");
        scanf("%d:%d",&(hora_inicio.horas),&(hora_inicio.minutos));
    }

    c->horas_fim.horas=definir_hora_fim(tipo_reserva,hora_inicio)->horas;   // define as horas_fim da tarefa
    c->horas_fim.minutos=definir_hora_fim(tipo_reserva,hora_inicio)->minutos;

    while(verificar_horario_fora_do_trabalho(&(c->horas_fim),&hora_inicio)){ //verifica se não sai do horario de trabalho 08h00 - 18h00
        printf("Não é possivel adicionar hora.\n");
        printf("Digite um valor válido (horario de trabalho: 8h00 - 18h00): ");
        scanf("%d:%d",&(hora_inicio.horas),&(hora_inicio.minutos));
        c->horas_fim.horas=definir_hora_fim(tipo_reserva,hora_inicio)->horas;   
        c->horas_fim.minutos=definir_hora_fim(tipo_reserva,hora_inicio)->minutos;
    }

    printf("DATA (DD/MM/AAAA): ");
    scanf("%d/%d/%d",&Data_temp.dia,&Data_temp.mes,&Data_temp.ano);

    while(dataValida(Data_temp)){ //verifica se a data é valida
        printf("Digite um valor válido: ");
        scanf("%d/%d/%d",&Data_temp.dia,&Data_temp.mes,&Data_temp.ano);
    }

    strcpy(c->Cliente.nome,nome);
    c->Cliente.telemovel=telemovel;
    c->Data.dia=Data_temp.dia;
    c->Data.mes=Data_temp.mes;
    c->Data.ano=Data_temp.ano;
    c->tipo_reserva=tipo_reserva;
    c->horas_inicio=hora_inicio;
    c->prox=NULL;

    return c;
}

//////////////////////////////////////////////////////////////////////////////////// 
//FUNÇÕES PARA ADICIONAR ELEMENTOS ÀS LISTAS
//////////////////////////////////////////////////////////////////////////////////// 

void adicionar_reserva_a_lista(Reserva cabeca, Reserva nova) { //ADICIONA UM NÓ À LISTA DAS RESERVAS
    Reserva anterior = cabeca;
    Reserva atual = anterior->prox;

    // Percorre a lista enquanto a data e hora da reserva atual forem menores que a da nova reserva
    while (atual != NULL && (comparar_reservas_cliente(atual->Data,nova->Data,atual->horas_inicio,nova->horas_inicio)==-1)){
        anterior = atual;
        atual = atual->prox;
    }

    // Insere o novo nó na lista na posição encontrada
    nova->prox = atual;
    anterior->prox = nova;
}

void adicionar_pre_reserva_a_lista(Pre_reserva cabeca_pre_reserva, Reserva nova) { //ADICIONA UM NÓ À LISTA DAS PRE RESERVAS
    Pre_reserva anterior = cabeca_pre_reserva;
    Pre_reserva atual = anterior->prox;

    // Cria um novo nó de pré-reserva e atribui a reserva como seu valor
    Pre_reserva novo_no = (Pre_reserva) malloc(sizeof(struct pre_reserva));
    if (novo_no == NULL) {
        printf("ERRO AO ALOCAR MEMÓRIA\n");
        return;
    }
    novo_no->pre_reservaa = *nova;
    novo_no->prox = NULL;

    // Percorre a lista enquanto a data e hora da reserva atual forem menores que a da nova reserva
    while (atual != NULL && comparar_reservas_cliente(atual->pre_reservaa.Data,novo_no->pre_reservaa.Data,atual->pre_reservaa.horas_inicio,novo_no->pre_reservaa.horas_inicio) == -1) {
        anterior = atual;
        atual = atual->prox;
    }

    // Insere o novo nó na lista na posição encontrada
    novo_no->prox = atual;
    anterior->prox = novo_no;
}

void adicionar_cliente_a_lista(L_cliente cabeca, L_cliente nova) { //ADICIONA À RESERVA
    L_cliente anterior = cabeca;
    L_cliente atual = anterior->prox;

    // Percorre a lista enquanto a data e hora da reserva atual forem menores que a da nova reserva
    while (atual != NULL && (comparar_reservas_cliente(atual->ord_cliente.Data,nova->ord_cliente.Data,atual->ord_cliente.horas_inicio,nova->ord_cliente.horas_inicio)==1)){ //adiciona à lista ficando sempre o mais recente à frente
        anterior = atual;
        atual = atual->prox;
    }

    // Insere o novo nó na lista na posição encontrada
    nova->prox = atual;
    anterior->prox = nova;
}

//////////////////////////////////////////////////////////////////////////////////// 
//FUNÇÕES PARA REMOVER ELEMENTOS DAS LISTAS
//////////////////////////////////////////////////////////////////////////////////// 

void remover_reserva(Reserva cabeca, Reserva telemovel_cliente) { //REMOVE CLIENTE DA RESERVA (função usada para o (adicionar reserva) caso não dê para adicionar)
    Reserva atual = cabeca->prox; // salta o header
    Reserva anterior = cabeca;

    // Percorre a lista até encontrar o nó a ser eliminado
    while (atual != NULL) {
        if ((atual->Cliente.telemovel == telemovel_cliente->Cliente.telemovel) && ((strcmp(atual->Cliente.nome,telemovel_cliente->Cliente.nome))==0)
        && ((comparar_reservas_cliente(atual->Data,telemovel_cliente->Data,atual->horas_inicio,telemovel_cliente->horas_inicio))==0)) {
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Caso o nó a ser eliminado seja encontrado
    if (atual != NULL) {
        anterior->prox = atual->prox;
        printf("Reserva eliminada com sucesso.\n");
        free(atual);
    } else {
        printf("Reserva não encontrada.\n");
    }
}

void remover_pre_reserva(Pre_reserva cabeca, long telemovel, char nome[], struct horas hora_inicio, struct data Data, int tipo) { //REMOVE CLIENTE DA PRE-RESERVA DANDO O Nº DE TELEMOVEL E O NOME E O NOME DO MESMO
    Pre_reserva atual = cabeca->prox; // salta o header
    Pre_reserva anterior = cabeca;

    // Percorre a lista até encontrar o nó a ser eliminado
    while (atual != NULL) {
        if ((atual->pre_reservaa.Cliente.telemovel == telemovel && 
           (strcmp(atual->pre_reservaa.Cliente.nome,nome))==0) && 
           (compara_datas(atual->pre_reservaa.Data,Data)==0)&&
           (compara_horas(atual->pre_reservaa.horas_inicio,hora_inicio))==0) {
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Caso o nó a ser eliminado seja encontrado
    if (atual != NULL) {
        anterior->prox = atual->prox;
        free(atual);
        printf("Pré-reserva eliminada com sucesso.\n");
    } else {
        printf("Reserva não encontrada.\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////// 
//CONVERSÕES
/////////////////////////////////////////////////////////////////////////////////////

Reserva converterPreReservaParaReserva(Pre_reserva pre_reserva) {
    Reserva reserva = NULL;

    if (pre_reserva != NULL) {
        reserva = (Reserva)malloc(sizeof(struct reserva));
        reserva->Cliente = pre_reserva->pre_reservaa.Cliente;
        reserva->Data = pre_reserva->pre_reservaa.Data;
        reserva->tipo_reserva = pre_reserva->pre_reservaa.tipo_reserva;
        reserva->horas_inicio = pre_reserva->pre_reservaa.horas_inicio;
        reserva->horas_fim = pre_reserva->pre_reservaa.horas_fim;
        reserva->prox = NULL;
    }

    return reserva;
}

///////////////////////////////////////////////////////////////////////////////////// 
//FUNÇÃO PARA ADCIONAR UMA PRE-RESERVA ÀS RESERVAS (verifica se o horario esta disponivel e aí adiciona)
/////////////////////////////////////////////////////////////////////////////////////

void PreReserva_para_Reserva(Reserva cabeca, Pre_reserva p, Reserva temporaria){
    Reserva principal=cabeca ; //salta o header
    Reserva temp=temporaria; //Reserva que vai ser eliminada
    Pre_reserva p_princial=p->prox;
    Pre_reserva p_temp=NULL;    
    
    while(p_princial!=NULL){ //percorre a lista das pre_reservas ate encontrar um espaço na hora em que se eliminou e adiciona-o às reservas
        Reserva c=converterPreReservaParaReserva(p_princial);
        if(horario_disponivel(c,temp)){ //compara se o elemento da pre_reserva e o que se quer eliminar estão dentro do horario
            p_temp=p_princial;
            adicionar_reserva_a_lista(principal,c); //adiciona o elemento das pre_reservas encontrado à reserva
            printf("Cliente %s com o numero %ld adicionado às reservas com sucesso.\n",p_temp->pre_reservaa.Cliente.nome,p_temp->pre_reservaa.Cliente.telemovel);
            remover_pre_reserva(p,p_temp->pre_reservaa.Cliente.telemovel,p_temp->pre_reservaa.Cliente.nome,p_temp->pre_reservaa.horas_inicio,
            p_temp->pre_reservaa.Data,p_temp->pre_reservaa.tipo_reserva); //remove o elemento das pre_reservas porque já foi adicionado às reservas
            break;
        }
        p_princial=p_princial->prox;
    }
}

///////////////////////////////////////////////////////////////////////////////////// 
//LISTA TEMPORARIA DO CLIENTE (lista para imprimir as reservas e pre_reservas por pessoa)
/////////////////////////////////////////////////////////////////////////////////////

L_cliente criar_cliente_reserva(Reserva r) { //Trocar os dados do tipo "Reserva", para "L_cliente"
    L_cliente p = (L_cliente)malloc(sizeof(l_cliente)); // Aloca memória para o novo nó
    Reserva reserva = r;
    p->ord_cliente = *reserva; // Copia a estrutura reserva para ord_cliente
    strcpy(p->lista, "Reservas");
    p->prox = NULL;

    return p;
}

L_cliente criar_cliente_pre_reserva(Pre_reserva r) { //Trocar os dados do tipo "Pre_reserva", para "L_cliente"
    L_cliente p = (L_cliente)malloc(sizeof(l_cliente)); // Aloca memória para o novo nó
    
    p->ord_cliente = r->pre_reservaa; // Copia a estrutura reserva para ord_cliente
    
    strcpy(p->lista, "Pré-reservas");
    p->prox = NULL;

    return p;
}

void adicionar_cliente_à_lista_temp(Reserva r, Pre_reserva p, L_cliente cabeca, long telemovel, char nome[]){ //adiciona à lista dependo se é da reserva ou pré_reserva
    Reserva r_principal=r->prox;
    Pre_reserva p_principal=p->prox;
/*
    if(!verificar_n_telemovel_igual(r,p,telemovel,nome)){
        printf("Cliente não encontrado.\n");
        return;
    }
*/
    while (r_principal!=NULL){ //Percorre a lista das reservas  
        L_cliente temp;
        if(((strcmp(r_principal->Cliente.nome,nome))==0) && (r_principal->Cliente.telemovel==telemovel)){ //Verifica todas as reservas que sejam do cliente
            temp=criar_cliente_reserva(r_principal);//Muda o tipo de estrutura 
            adicionar_cliente_a_lista(cabeca,temp); //adiciona à lista
        } 
        r_principal=r_principal->prox;
    }
    while (p_principal!=NULL){ //Fazer o mesmo mas para as pre_reservas
        L_cliente tempo;
        if((strcmp(p_principal->pre_reservaa.Cliente.nome,nome))==0 && (p_principal->pre_reservaa.Cliente.telemovel==telemovel)){
            tempo=criar_cliente_pre_reserva(p_principal);
            adicionar_cliente_a_lista(cabeca,tempo);
        }
        p_principal=p_principal->prox;
    }
}

///////////////////////////////////////////////////////////////////////////////////// 
//                                  FICHEIROS
/////////////////////////////////////////////////////////////////////////////////////

void lerReservasDeArquivo(Reserva r) {
    FILE* arquivo = fopen("PROJETO/BaseDeDadosReserva.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo das reservas.\n");
        exit(1);
    }

    // Vê se o ficheiro está vazio
    if (fgetc(arquivo) == EOF) {
        printf("O arquivo das reservas está vazio.\n");
        fclose(arquivo);
        return;
    }

    // Reset the file position to the beginning
    rewind(arquivo);

    Reserva cabeca = r; // Head of the reservation list
    int leituras; // Variable to store the number of successful readings

    while (!feof(arquivo)) {
        Reserva novaReserva = (Reserva)malloc(sizeof(reserva));
        if (novaReserva == NULL) {
            printf("Erro ao alocar memória.\n");
            break;
        }

        leituras = fscanf(arquivo, "%ld %s %d/%d/%d %d %d:%d %d:%d",
                          &(novaReserva->Cliente.telemovel),
                          novaReserva->Cliente.nome,
                          &(novaReserva->Data.dia),
                          &(novaReserva->Data.mes),
                          &(novaReserva->Data.ano),
                          &(novaReserva->tipo_reserva),
                          &(novaReserva->horas_inicio.horas),
                          &(novaReserva->horas_inicio.minutos),
                          &(novaReserva->horas_fim.horas),
                          &(novaReserva->horas_fim.minutos));

        if (leituras != 10) {
            printf("Erro ao ler informações do arquivo (reservas).\n");
            free(novaReserva);
            exit(1);
        }

        novaReserva->prox = NULL;

        // If it's the first reservation, assign it as the head of the list
        if (cabeca == NULL) {
            cabeca = novaReserva;
        } else {
            // Add the new reservation to the list
            adicionar_reserva_a_lista(cabeca, novaReserva);
        }
    }

    fclose(arquivo);
}

void lerPreReservasDeArquivo(Pre_reserva p) {
    FILE* arquivo = fopen("PROJETO/BaseDeDadosPreReserva.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.1\n");
        exit(1);
    }

    // Vê se o ficheiro está vazio
    if (fgetc(arquivo) == EOF) {
        printf("O arquivo das pré-reservas está vazio.\n");
        fclose(arquivo);
        return;
    }

    // Reset the file position to the beginning
    rewind(arquivo);

    Pre_reserva cabeca = p; // Head of the reservation list
    int leituras; // Variable to store the number of successful readings

    while (!feof(arquivo)) {
        Reserva novaReserva = (Reserva)malloc(sizeof(reserva));
        if (novaReserva == NULL) {
            printf("Erro ao alocar memória.\n");
            break;
        }

        leituras = fscanf(arquivo, "%ld %s %d/%d/%d %d %d:%d %d:%d",
                          &(novaReserva->Cliente.telemovel),
                          novaReserva->Cliente.nome,
                          &(novaReserva->Data.dia),
                          &(novaReserva->Data.mes),
                          &(novaReserva->Data.ano),
                          &(novaReserva->tipo_reserva),
                          &(novaReserva->horas_inicio.horas),
                          &(novaReserva->horas_inicio.minutos),
                          &(novaReserva->horas_fim.horas),
                          &(novaReserva->horas_fim.minutos));

        if (leituras != 10) {
            printf("Erro ao ler informações do arquivo (pré-reserva).\n");
            free(novaReserva);
            exit(1);
        }

        novaReserva->prox = NULL;

        // If it's the first reservation, assign it as the head of the list
        if (cabeca == NULL) {
            cabeca->pre_reservaa = *novaReserva;
        } else {
            // Add the new reservation to the list
            adicionar_pre_reserva_a_lista(cabeca, novaReserva);
        }
    }

    fclose(arquivo);
}

void reescreverReservasNoArquivo(Reserva listaReservas) {
    FILE* arquivo = fopen("PROJETO/BaseDeDadosReserva.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Reserva reservaAtual = listaReservas->prox;
    int isLastReservation = 0;

    while (reservaAtual != NULL) {
        if (reservaAtual->prox == NULL) {
            isLastReservation = 1;
        }

        fprintf(arquivo, "%ld %s %02d/%02d/%04d %d %02d:%02d %02d:%02d%s",
            reservaAtual->Cliente.telemovel,
            reservaAtual->Cliente.nome,
            reservaAtual->Data.dia,
            reservaAtual->Data.mes,
            reservaAtual->Data.ano,
            reservaAtual->tipo_reserva,
            reservaAtual->horas_inicio.horas,
            reservaAtual->horas_inicio.minutos,
            reservaAtual->horas_fim.horas,
            reservaAtual->horas_fim.minutos,
            isLastReservation ? "" : "\n");

        isLastReservation = 0;
        reservaAtual = reservaAtual->prox;
    }

    fclose(arquivo);
}

void reescreverPreReservasNoArquivo(Pre_reserva listaPreReservas) {
    FILE* arquivo = fopen("PROJETO/BaseDeDadosPreReserva.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Pre_reserva preReservaAtual = listaPreReservas->prox;
    int isLastPreReserva = 0;

    while (preReservaAtual != NULL) {
        if (preReservaAtual->prox == NULL) {
            isLastPreReserva = 1;
        }

        fprintf(arquivo, "%ld %s %02d/%02d/%04d %d %02d:%02d %02d:%02d%s",
            preReservaAtual->pre_reservaa.Cliente.telemovel,
            preReservaAtual->pre_reservaa.Cliente.nome,
            preReservaAtual->pre_reservaa.Data.dia,
            preReservaAtual->pre_reservaa.Data.mes,
            preReservaAtual->pre_reservaa.Data.ano,
            preReservaAtual->pre_reservaa.tipo_reserva,
            preReservaAtual->pre_reservaa.horas_inicio.horas,
            preReservaAtual->pre_reservaa.horas_inicio.minutos,
            preReservaAtual->pre_reservaa.horas_fim.horas,
            preReservaAtual->pre_reservaa.horas_fim.minutos,
            isLastPreReserva ? "" : "\n");

        isLastPreReserva = 0;
        preReservaAtual = preReservaAtual->prox;
    }

    fclose(arquivo);
}

///////////////////////////////////////////////////////////////////////////////////// 
//                              FUNÇÕES PARA O MAIN
/////////////////////////////////////////////////////////////////////////////////////

void acabar_o_dia_main(Reserva r, Pre_reserva p){ //função para retirar as reservas e pre reservas dum determinado dia
    Reserva r_principal=r->prox;
    Pre_reserva p_principal=p->prox;

    struct data Data_temp;
    printf("Insira o dia a remover: ");
    scanf("%d/%d/%d",&Data_temp.dia,&Data_temp.mes,&Data_temp.ano);
    while(dataValida(Data_temp)){ //verifica se a data é valida
        printf("Não é possivel adicionar data.\n");
        printf("Digite um valor válido: ");
        scanf("%d/%d/%d",&Data_temp.dia,&Data_temp.mes,&Data_temp.ano);
    }

    while (r_principal!=NULL){
        Reserva temp = r_principal;
        if(compara_datas(r_principal->Data,Data_temp)<=0){
            remover_reserva(r,temp);
        }
        r_principal=r_principal->prox;
    }
    while (p_principal!=NULL){
        Pre_reserva temporario = p_principal;
        if(compara_datas(p_principal->pre_reservaa.Data,Data_temp)<=0){
            remover_pre_reserva(p,temporario->pre_reservaa.Cliente.telemovel,temporario->pre_reservaa.Cliente.nome,temporario->pre_reservaa.horas_inicio,temporario->pre_reservaa.Data,temporario->pre_reservaa.tipo_reserva);
        }
        p_principal=p_principal->prox;
    }
}

void fazer_reserva_main(Reserva r, Pre_reserva p){
    Reserva temp=criar_reserva(r,p);
    adicionar_reserva_a_lista(r,temp);
        if (verificar_n_telemovel_igual(r,p,temp->Cliente.telemovel,temp->Cliente.nome)) { //VERIFICAR SE JÁ EXISTE O CLIENTE NA RESERVA PELO Nº DE TELEMOVEL
                                                                                                              //Verficiar se a data é válida
            remover_reserva(r,temp); //ELIMINA DA LISTA DAS RESERVAS
            
        } else if (existe_hora_preenchida(r,temp)) { //VERIFICAR SE A HORA JÁ ESTÁ PREENCHIDA   

            adicionar_pre_reserva_a_lista(p,temp); //ADICIONA À PRE_RESERVA               
            remover_reserva(r,temp); //ELIMINA DA LISTA DAS RESERVAS

            printf("Reserva adicionada às pré-reservas.\n"); 
            printf("Não foi possivel adicionar a reserva.\n"); 
            printf("\n");

        } else {
            printf("Reserva adicionada com sucesso.\n");
            printf("\n");
        }   
}

void remover_pre_reserva_main(Pre_reserva p){ //REMOVE PRE-RESERVA NO MAIN
    struct horas hora_inicio;
    struct horas hora_fim;
    struct data Data_temp;
    char nome[100];
    int tipo_reserva;
    long telemovel;
    
    printf("NOME: ");
    scanf("%s",nome);

    printf("TELEMOVEL: ");
    scanf("%ld",&telemovel);

    printf("TIPO DE RESERVA (0 = MANUTENÇÃO || 1 = LAVAGEM): ");
    scanf("%d",&tipo_reserva);

    printf("HORAS (HH:MM): ");
    scanf("%d:%d",&(hora_inicio.horas),&(hora_inicio.minutos));

    printf("DATA (DD/MM/AAAA): ");
    scanf("%d/%d/%d",&Data_temp.dia,&Data_temp.mes,&Data_temp.ano);

    //valta verificar se o cliente existe nas pre_reservas
    remover_pre_reserva(p,telemovel,nome,hora_inicio,Data_temp,tipo_reserva);
}

void remover_reserva_main(Reserva cabeca, Pre_reserva p){
    Reserva principal=cabeca->prox;
    Reserva c=criar_reserva(cabeca,p);
    Reserva temp=NULL;

    while(principal!=NULL){ //VERIFICAR SE O CLIENTE EXISTE NA LISTA DAS RESERVAS
        if((principal->Cliente.telemovel==c->Cliente.telemovel) && (strcmp(principal->Cliente.nome,c->Cliente.nome))==0 && 
            ((comparar_reservas_cliente(principal->Data,c->Data,principal->horas_inicio,c->horas_inicio))==0)){
            temp=principal; //GUARDA O CLIENTE QUE VAI SER ELIMINADO NA VARIAVEL "temp"
            break;
        }
        principal=principal->prox;
    }

    if(temp==NULL){ //caso não encontre quem quer ser eliminado
        printf("Reserva não encontrada. (não pode ser eliminada)\n");
    } else {
        PreReserva_para_Reserva(cabeca,p,temp);
        remover_reserva(cabeca,c);
        printf("Reserva removida com sucesso.\n");
    }
}

void imprimir_cliente_main(Reserva r,Pre_reserva p, L_cliente l){
    char nome[100];
    long telemovel;
    printf("NOME: ");
    scanf("%s",nome);
    printf("TELEMÓVEL: ");
    scanf("%ld",&telemovel);

    adicionar_cliente_à_lista_temp(r,p,l,telemovel,nome);
    imprimir_cliente(l);
    free(l);
}

void menu(Reserva r, Pre_reserva p, L_cliente l, int *opcao) {
    printf("\nInsira o numero correspondente a operacao que pretende realizar:\n"
           "\t\t\t1 : 'Fazer uma reserva'\n"
           "\t\t\t2 : 'Cancelar reserva'\n"
           "\t\t\t3 : 'Cancelar pré-reserva'\n"
           "\t\t\t4 : 'Ver reservas'\n"
           "\t\t\t5 : 'Ver pre-reservas'\n"
           "\t\t\t6 : 'Ver Cliente'\n"
           "\t\t\t7 : 'Acabar o dia'\n"
           "\t\t\t8 : 'Guardar dados no ficheiro'\n"
           "\t\t\t0 : 'Sair'\n"

           "Opcao: ");

    scanf("%d", opcao);
    while(*opcao < 0 || *opcao > 8){
        printf("Opção inválida\n");
        printf("Digite uma opção válida: ");
        scanf("%d", opcao);
    }
    if (*opcao == 1) {
        fazer_reserva_main(r, p);
    }
    if (*opcao == 2) {
        remover_reserva_main(r, p);
    }
    if (*opcao == 3) {
        remover_pre_reserva_main(p);
    }
    if (*opcao == 4) {
        imprimir_reservas(r);
    }
    if (*opcao == 5) {
        imprimir_pre_reservas(p);
    }
    if (*opcao == 6) {
        imprimir_cliente_main(r,p,l);
    }
    if (*opcao == 7) {
        acabar_o_dia_main(r,p);
    }
    if (*opcao == 8) {
        reescreverReservasNoArquivo(r);     //Reescreve os dados das reservas e pre reservas nos ficheiros
        reescreverPreReservasNoArquivo(p);
        printf("Dados guardados com sucesso.\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////// 
//MAIN
///////////////////////////////////////////////////////////////////////////////////// 

int main(){
    Reserva r=criar_lista_reserva();
    Pre_reserva p=criar_lista_pre_reserva();
    L_cliente l=criar_lista_l_cliente();

    lerReservasDeArquivo(r);            //Lê os ficheiros com os dados e guarda-os nas respectivas listas
    lerPreReservasDeArquivo(p);

    int opcao = -1;
    while (opcao != 0) {
        menu(r,p,l,&opcao);
    }

    reescreverReservasNoArquivo(r);     //Reescreve os dados das reservas e pre reservas nos ficheiros
    reescreverPreReservasNoArquivo(p);
    free(r);
    free(p);

    return 0;
}
