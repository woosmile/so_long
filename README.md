# so_long

- 42에서 제공하는 그래픽 라이브러리를 통해 2D 미니 게임을 만드는 것

## 학습 내용

- 게임에서 사용되는 맵이 탈출 가능한지 검사하기 위한 Flood fill 알고리즘
- 42 그래픽 라이브러리 minilibx 사용 방법

## 구조체 설명

- 특정 위치의 X, Y 좌표를 저장하는 구조체

	```
	typedef struct s_pos
	{
		int x;
		int y;
	}	t_pos;
	```

- 맵 정보 : 가로 길이, 세로 길이, 출구 개수, 플레이어 개수, 플레이어의 좌표, 플레이어의 걸음, 수집품 개수
- minilibx에 필요한 변수 : mlx, win, img 포인터, 출력할 이미지에 대한 width, height 정보

	```
	typedef struct s_var
	{
		int	x;
		int	y;
		int	end;
		int	player;
		struct s_pos	p_pos;
		int	step;
		int	collect;
		char	**map;
		void	*mlx;
		void	*win;
		void	*img;
		int	img_width;
		int	img_height;
	}	t_var;
	```

- flood-fill 에서 사용되는 큐 노드, 큐 구조체

	```
	typedef struct s_node
	{
		struct s_pos	pos;
		struct s_node	*next;
	}	t_node;
	
	typedef struct s_queue
	{
		t_node	*front;
		t_node	*rear;
		int	count;
	}	t_queue; 
	```

- 키 이벤트에 사용되는 열거형

	```
	typedef enum e_key
	{
		W = 13,
		A = 0,
		S,
		D,
		L = 123,
		R,
		DN,
		UP,
		ESC = 53,
	}	t_key;
	```

## 함수 설명 (Mandatory Part)

### check_map_main

- 유효한 맵인지 검사하는 함수들을 차례로 불러오는 함수, 다음과 같은 검사를 진행함
- 중간에 읽은 맵의 정보를 가지고 개행을 구분자로 split을 해서 2차원 배열로 만듬
- 문자열의 총 개수를 확인하여 맵의 세로축을 측정함

### check_map_name

- 맵의 이름이 .ber로 끝나는지 검사함
- strncmp를 사용하여 두번째 인자(av[1])의 가장 끝 문자부터 4글자가 “.ber”인지 검사함

### read_map_data

- 맵 이름 검사가 끝나면 맵의 정보를 읽어옴
- read 함수를 통해 1글자씩 읽어서 char 형 배열 2칸 중 첫번째 칸에 저장함 (word[0])
- 그리고 두번째 칸에는 NULL을 넣어서 문자열로 만들어줌 (word[1] = 0)
- 그런 다음 read_len이 0이 될 때 까지(다 읽을 때까지) 한 글자씩 ft_strjoin으로 이어 붙임
- 완성된 맵 문자열 한 줄 반환

### input_map_info

- 탈출구, 수집품, 플레이어, 벽, 빈공간, 개행에 대한 문자를 검사함
- 탈출구, 수집품, 플레이어에 대해서는 개수도 확인함
- 유효하지 않은 문자가 있으면 잘못된 맵으로 판단함

### check_map_info

- 탈출구, 플레이어는 단 1개만 존재해야하고 수집품은 1개 이상 있어야함
- 오브젝트의 개수가 조건에 맞지 않으면 잘못된 맵으로 판단
- 또한 지도의 세로 축이 3 이상인지 확인함
    - 가장자리가 벽으로 둘러쌓여 있어야 하므로 최소 3이상은 되어야 빈공간이 생김

### check_edge

- 맵의 가장자리가 벽으로 둘러쌓여있는지 확인함
- 추가로 맵의 가로축을 측정함
- 첫 번째 행, 마지막 행은 반드시 1의 문자로만 구성되어 있어야함
- 위 경우를 제외한 중간에 있는 행은 첫번째, 마지막 문자만 1로 구성되어있어야 함

### check_rectangular

- 맵이 직사각형인지 확인함
- 맵의 가로, 세로축이 같으면 정사각형이므로 유효하지 않은 맵으로 판단함
- 맵의 가로축 값과 각 행의 문자 개수를 비교하여 같은지 확인

### check_map_escapable

- 큐 자료구조를 활용하여 flood-fill 알고리즘을 구현함
- 플레이어가 탈출구에 도달할 수 있는지, 플레이어가 모든 수집품에 도달할 수 있는지 확인함
- 맵 정보와 똑같은 2차원 배열을 하나 더 만듬 (visit)
- initial_queue를 통해 플레이어의 위치 정보(x, y)를 확인하고 이 정보에 대한 노드를 생성 후 queue에 넣음 (enqueue)
- queue에 넣을 때 visit 배열에서 해당 플레이어 위치 인덱스 값을 0에서 1로 바꿈
- player_to_exit 함수를 통해 dequeue한 좌표의 상(0, -1) / 하(0, 1) / 좌(-1, 0) / 우(1, 0) 인덱스의 값을 검사함
- 접근할 수 있는 공간(0, C)이 이 있고 그 공간이 visit에 아직 0인 방문하지 않은 좌표라면 visit에 그 좌표를 방문표시하고 enqueue 진행
- 탈출구(E)를 만날 때 까지 위의 과정을 반복하고 queue의 개수가 0이 되면 탈출구를 만나지 못한 것이기 때문에 유효하지 않은 맵으로 판단
- player_to_collection도 똑같은 방식으로 진행하고 맵 전체를 다 확인했는데 수집품의 개수가 0이 아니면 접근할 수 없는 수집품이 있다는 것이기 때문에 유효하지 않은 맵으로 판단함

### draw_field

- 프로그램과 하드웨어를 연결하는 mlx 포인터, 창에 대한 win 포인터를 초기화하고 맵 정보를 바탕으로 벽, 빈공간, 수집품, 탈출구, 플레이어의 초기 상태를 그리고 step의 초기값을 출력함
- void *mlx_init()
    - mlx 초기화 함수
- void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
    - win 초기화 함수
    - (mlx 포인터, 창의 가로 크기, 창의 세로 크기, 창 제목)

### draw_tile, wall, collection, exit

- 빈공간, 벽, 수집품, 탈출구를 그리는 함수
- void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)
    - xpm 파일로 부터 정보를 읽어서 void * 형식으로 반환함
    - (mlx 포인터, xpm 파일 경로, 읽어온 xpm 파일의 가로 픽셀 개수, 읽어온 xpm 파일의 세로 픽셀 개수)
- int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
    - void * 형식의 image 포인터의 정보를 통해 화면에 그려주는 함수
    - (mlx 포인터, win 포인터, img 포인터, 이미지를 그릴 x좌표, y좌표)
    - 이미지를 그릴 x좌표, y좌표는 왼쪽 상단을 기준으로 0, 0임

### draw_player_pos

- 해당 좌표에 단 한번만 그리는 함수

### mlx_key_hook

- 키보드 이벤트가 발생했을 때 불러올 함수와 그 함수에 전달될 인자를 설정하는 함수
- mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param)
    - (win 포인터, 불러올 함수명, 함수에 전달될 포인터)

### key_hook

- 키보드 이벤트가 발생했을 때 불러와지는 방향키, wasd로 움직였을 때의 적절한 함수를 불러오고 움직인 횟수를 쉘 상에 표시하는 함수

### key_up, down, left, right

- 움직일 위치에 벽(1)이 있는지 확인하고 없으면 움직이는(정확히는 플레이어의 위치를 옮기고 다시 그리는) 동작을 진행함
    1. 움직이기 전 현재 위치에 탈출구가 있는지 확인하고 있으면 빈공간(tile)을 그리고 탈출구를 그려서 플레이어의 이미지를 지움
    2. 만약 탈출구가 없다면 그냥 빈공간만 그림
    3. 움직이려는 위치로 플레이어의 좌표를 옮김
    4. 움직인 위치에 탈출구 또는 수집품이 있다면 해당하는 함수 불러옴 (detect_exit, detect_collect)
    5. 없다면 해당 위치에 플레이어를 그림
    6. 위와 같은 방식으로 움직이는 동작을 구현함

### detect_exit

- 플레이어의 위치가 탈출구라면 불러와지는 함수
- collect의 개수를 확인하고 0개가 아니면은 해당 위치에 플레이어를 이미지를 출력하고 특정 메세지 출력
- 0개면은 특정 메세지 출력하고 mlx_destroy_window 함수 불러오고 exit(0)로 프로그램 종료
    - int mlx_destroy_window(void *mlx_ptr, void *win_ptr)

### detect_coin

- 플레이어의 위치가 수집품이 있는 위치라면 불러와지는 함수
- collect의 개수를 감소시키고 맵 데이터를 0으로 바꿈
- 플레이어가 수집품에 닿자마자 없어지는 것으로 구현하고 싶어서 빈공간을 출력한 후 플레이어를 출력하는 것으로 구현함

### mlx_hook

- 창에서 좌측 상단 X 버튼이 눌렸을 때 프로그램이 종료되도록 하기 위해 사용한 함수
- int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
    - (win 포인터, 이벤트 넘버링, 이벤트에 대한 마스크, 함수 포인터, 함수에 전달될 자료)
- mlx_key_hook, mlx_mouse_hook과 같은 함수들은 사실 이 함수를 불러오는 것이라고 함

### mlx_loop

- 창에 대한 동작이 계속 반복되도록 무한 루프를 돌려주는 함수
- mlx_loop(void *mlx_ptr)

## 함수 설명 (Bonus Part)

### srand(time(NULL))

- 현재 시간값을 seed로 해서 랜덤 값을 생성하도록 준비함
- random 함수는 프로그램이 빌드될 때의 srand로 설정한 seed로 난수를 생성하는데 seed가 매번 똑같다면 매번 실행할 때마다 똑같은 난수만 나오게 됨
- time(NULL) 즉, 현재 시간값을 seed로 줘서 진정한 난수 값을 생성할 수 있도록 함

### check_map_main

- 적 위치에 해당하는 X에 대한 검사가 추가됨

### find_enemy_pos

- 적 X, Y 좌표를 가져오는 함수

### mlx_loop_hook

- 이벤트가 발생하지 않아도 함수 포인터로 지정한 함수를 계속 불러오는 함수
- int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param)
    - (mlx 포인터, 함수 포인터, 함수에 전달될 포인터 인자)

### move_enemy

- 난수에 4로 나눈 나머지 값인 0(상), 1(하), 2(좌), 3(우)에 해당하는 값으로만 num에 할당함
- mlx_loop_hook을 통해 호출되며 호출되는 속도가 너무 빨라서 delay 변수를 통해 속도를 조절함

### enemy_encountered

- 플레이어와 적이 마주쳤는지 검사하는 함수
- 매 이벤트가 발생 할 때마다 검사함 (적이 움직이거나, 플레이어가 움직이거나)

### initial_sprite

- 적과 플레이어의 sprite 애니메이션 구현을 위한 xpm 파일들의 경로를 지정하는 함수
- 상, 하, 좌, 우 각 움직임에 따라 3개의 xpm으로 표현함
- xpm 파일들의 경로 저장을 위해 구조체에  char *sprite[4][3] 멤버변수가 추가됨

### draw_field

- 대부분 동일하나 걸음 수에 대한 정보가 창에 표시되도록 변경함 (draw_step)

### draw_step

- 숫자가 한번 표시되면 계속 보이게 되므로 숫자를 표시하기 전에 이전 숫자에 대한 흔적을 먼저 지운 다음 새로운 숫자를 표시하는 방식으로 진행함
- int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)
    - (mlx 포인터, win 포인터, x좌표, y좌표, 문자색상, 표시할 문자)
- 숫자는 32, 36 좌표에 표시하도록 함
- 숫자가 32, 0 / 32, 32 에 걸쳐서 표시되므로 두 영역에 대해서 빈공간을 그려주고 벽을 그려줌
- 숫자가 문자형식으로 표시되어야 하므로 ft_itoa 함수 사용

### key_up, down, left, right

- 적이 움직이는 동작에도 이 함수를 사용하기로 함
- 다음과 같은 상황 때문에 key_hook이 호출하는지, move_enemy 함수가 호출하는지에 따라서 flag를 기준으로 삼아 다른 동작을 하게끔 구현함 (flag = 0 플레이어 / flag = 1 적)
    - 적이 수집품이나 탈출구에 닿으면 아무런 동작이 일어나지 않아야 함
    - 적이 움직인 횟수는 플레이어의 움직인 횟수에 포함되지 않아야 함
    - 플레이어가 수집품에 닿으면 수집품이 사라져야 하지만 적군은 그러면 안됨

## 보완할 점

- 다음 과제부터는 Error 처리 하는 부분을 하나로 통합하기
    - so_long 에서는 검사를 하나씩 하고 결과에 따라 Error를 처리하도록 해서 Error의 종류를 확인하는데 있어서 좀 불편하다는 느낌이 들었음
