#include <check.h>

#include "../back/s21_3DViewer.h"

#define EPS 1e-06

START_TEST(parser_1) {
  int error = 0;
  Objects obj = {0, NULL, NULL};
  error = s21_3DViewer("xxx.obj", &obj);
  StructureCleaning(&obj);
  ck_assert_int_eq(error, ERROR);
}
END_TEST

START_TEST(parser_2) {
  char *filename = NULL;
  int error = 0;
  Objects obj = {0, NULL, NULL};
  error = s21_3DViewer(filename, &obj);
  StructureCleaning(&obj);
  ck_assert_int_eq(error, ERROR);
}
END_TEST

START_TEST(affine_move_X_1) {
  Objects obj = {0, NULL, NULL};
  const char *filename = "ObjFiles/cube.obj";
  s21_3DViewer(filename, &obj);
  double vertices_arr[8][3] = {{0.0000000, -1.0000000, -1.0000000},
                               {0.0000000, -1.0000000, 1.0000000},
                               {0.0000000, 1.0000000, -1.0000000},
                               {0.0000000, 1.0000000, 1.0000000},
                               {2.0000000, -1.0000000, -1.0000000},
                               {2.0000000, -1.0000000, 1.0000000},
                               {2.0000000, 1.0000000, -1.0000000},
                               {2.0000000, 1.0000000, 1.0000000}

  };
  MoveObjectX(obj.vertic, 1);
  ck_assert_int_eq(obj.vertic->rows, 8);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j], EPS);
  }
  StructureCleaning(&obj);
}
END_TEST

START_TEST(affine_move_Y_1) {
  Objects obj = {0, NULL, NULL};
  const char *filename = "ObjFiles/cube.obj";
  s21_3DViewer(filename, &obj);
  double vertices_arr[8][3] = {{-1.0000000, 0.0000000, -1.0000000},
                               {-1.0000000, 0.0000000, 1.0000000},
                               {-1.0000000, 2.0000000, -1.0000000},
                               {-1.0000000, 2.0000000, 1.0000000},
                               {1.0000000, 0.0000000, -1.0000000},
                               {1.0000000, 0.0000000, 1.0000000},
                               {1.0000000, 2.0000000, -1.0000000},
                               {1.0000000, 2.0000000, 1.0000000}

  };
  MoveObjectY(obj.vertic, 1);
  ck_assert_int_eq(obj.vertic->rows, 8);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j], EPS);
  }
  StructureCleaning(&obj);
}
END_TEST

START_TEST(affine_move_Z_1) {
  Objects obj = {0, NULL, NULL};
  const char *filename = "ObjFiles/cube.obj";
  s21_3DViewer(filename, &obj);
  double vertices_arr[8][3] = {{-1.0000000, -1.0000000, 0.0000000},
                               {-1.0000000, -1.0000000, 2.0000000},
                               {-1.0000000, 1.0000000, 0.0000000},
                               {-1.0000000, 1.0000000, 2.0000000},
                               {1.0000000, -1.0000000, 0.0000000},
                               {1.0000000, -1.0000000, 2.0000000},
                               {1.0000000, 1.0000000, 0.0000000},
                               {1.0000000, 1.0000000, 2.0000000}

  };
  MoveObjectZ(obj.vertic, 1);
  ck_assert_int_eq(obj.vertic->rows, 8);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j], EPS);
  }
  StructureCleaning(&obj);
}
END_TEST

START_TEST(affine_Rotation_X_1) {
  Objects obj = {0, NULL, NULL};
  const char *filename = "ObjFiles/cube.obj";
  s21_3DViewer(filename, &obj);
  double vertices_arr[8][3] = {{-1.0000000, -0.366025, -1.366025},
                               {-1.0000000, -1.366025, 0.366025},
                               {-1.0000000, 1.366025, -0.366025},
                               {-1.0000000, 0.366025, 1.366025},
                               {1.0000000, -0.366025, -1.366025},
                               {1.0000000, -1.366025, 0.366025},
                               {1.0000000, 1.366025, -0.366025},
                               {1.0000000, 0.366025, 1.366025}

  };
  RotationX(obj.vertic, 30);
  ;
  ck_assert_int_eq(obj.vertic->rows, 8);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j], EPS);
  }
  StructureCleaning(&obj);
}
END_TEST

START_TEST(affine_Rotation_Y_1) {
  Objects obj = {0, NULL, NULL};
  const char *filename = "ObjFiles/cube.obj";
  s21_3DViewer(filename, &obj);
  double vertices_arr[8][3] = {

      {-0.366025, -1.0000000, -1.366025},
      {-1.366025, -1.0000000, 0.366025},
      {-0.366025, 1.0000000, -1.366025},
      {-1.366025, 1.0000000, 0.366025},
      {1.366025, -1.0000000, -0.366025},
      {0.366025, -1.0000000, 1.366025},
      {1.366025, 1.0000000, -0.366025},
      {0.366025, 1.0000000, 1.366025}

  };
  RotationY(obj.vertic, 30);
  ;
  ck_assert_int_eq(obj.vertic->rows, 8);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j], EPS);
  }
  StructureCleaning(&obj);
}
END_TEST

START_TEST(affine_Rotation_Z_1) {
  Objects obj = {0, NULL, NULL};
  const char *filename = "ObjFiles/cube.obj";
  s21_3DViewer(filename, &obj);
  double vertices_arr[8][3] = {

      {-0.366025, -1.366025, -1.0000000},
      {-0.366025, -1.366025, 1.0000000},
      {-1.366025, 0.366025, -1.0000000},
      {-1.366025, 0.366025, 1.0000000},
      {1.366025, -0.366025, -1.0000000},
      {1.366025, -0.366025, 1.0000000},
      {0.366025, 1.366025, -1.0000000},
      {0.366025, 1.366025, 1.0000000}

  };
  RotationZ(obj.vertic, 30);
  ck_assert_int_eq(obj.vertic->rows, 8);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j], EPS);
  }
  StructureCleaning(&obj);
}
END_TEST

START_TEST(affine_scale_1) {
  Objects obj = {0, NULL, NULL};
  const char *filename = "ObjFiles/cube.obj";
  s21_3DViewer(filename, &obj);
  double vertices_arr[8][3] = {
      {-3.0000000, -3.0000000, -3.0000000}, {-3.0000000, -3.0000000, 3.0000000},
      {-3.0000000, 3.0000000, -3.0000000},  {-3.0000000, 3.0000000, 3.0000000},
      {3.0000000, -3.0000000, -3.0000000},  {3.0000000, -3.0000000, 3.0000000},
      {3.0000000, 3.0000000, -3.0000000},   {3.0000000, 3.0000000, 3.0000000}};
  s21_mult_number(obj.vertic, 3);
  ck_assert_int_eq(obj.vertic->rows, 8);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j], EPS);
  }
  StructureCleaning(&obj);
}
END_TEST

START_TEST(affine_scale_2) {
  Objects obj = {0, NULL, NULL};
  const char *filename = "ObjFiles/cube.obj";
  s21_3DViewer(filename, &obj);
  double vertices_arr[8][3] = {{3.0000000, 3.0000000, 3.0000000},
                               {3.0000000, 3.0000000, -3.0000000},
                               {3.0000000, -3.0000000, 3.0000000},
                               {3.0000000, -3.0000000, -3.0000000},
                               {-3.0000000, 3.0000000, 3.0000000},
                               {-3.0000000, 3.0000000, -3.0000000},
                               {-3.0000000, -3.0000000, 3.0000000},
                               {-3.0000000, -3.0000000, -3.0000000}};
  s21_mult_number(obj.vertic, -3);
  ck_assert_int_eq(obj.vertic->rows, 8);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j], EPS);
  }
  StructureCleaning(&obj);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Check");
  TCase *tc_parser_1;
  tc_parser_1 = tcase_create("parser_1");
  suite_add_tcase(s, tc_parser_1);
  tcase_add_test(tc_parser_1, parser_1);

  TCase *tc_parser_2;
  tc_parser_2 = tcase_create("parser_2");
  suite_add_tcase(s, tc_parser_2);
  tcase_add_test(tc_parser_2, parser_2);

  TCase *tc_affine_move_X_1;
  tc_affine_move_X_1 = tcase_create("affine_move_X_1");
  suite_add_tcase(s, tc_affine_move_X_1);
  tcase_add_test(tc_affine_move_X_1, affine_move_X_1);

  TCase *tc_affine_move_Y_1;
  tc_affine_move_Y_1 = tcase_create("affine_move_Y_1");
  suite_add_tcase(s, tc_affine_move_Y_1);
  tcase_add_test(tc_affine_move_Y_1, affine_move_Y_1);

  TCase *tc_affine_move_Z_1;
  tc_affine_move_Z_1 = tcase_create("affine_move_Z_1");
  suite_add_tcase(s, tc_affine_move_Z_1);
  tcase_add_test(tc_affine_move_Z_1, affine_move_Z_1);

  TCase *tc_affine_Rotation_X_1;
  tc_affine_Rotation_X_1 = tcase_create("affine_Rotation_X_1");
  suite_add_tcase(s, tc_affine_Rotation_X_1);
  tcase_add_test(tc_affine_Rotation_X_1, affine_Rotation_X_1);

  TCase *tc_affine_Rotation_Y_1;
  tc_affine_Rotation_Y_1 = tcase_create("affine_Rotation_Y_1");
  suite_add_tcase(s, tc_affine_Rotation_Y_1);
  tcase_add_test(tc_affine_Rotation_Y_1, affine_Rotation_Y_1);

  TCase *tc_affine_Rotation_Z_1;
  tc_affine_Rotation_Z_1 = tcase_create("affine_Rotation_Z_1");
  suite_add_tcase(s, tc_affine_Rotation_Z_1);
  tcase_add_test(tc_affine_Rotation_Z_1, affine_Rotation_Z_1);

  TCase *tc_affine_scale_1;
  tc_affine_scale_1 = tcase_create("affine_scale_1");
  suite_add_tcase(s, tc_affine_scale_1);
  tcase_add_test(tc_affine_scale_1, affine_scale_1);

  TCase *tc_affine_scale_2;
  tc_affine_scale_2 = tcase_create("affine_scale_2");
  suite_add_tcase(s, tc_affine_scale_2);
  tcase_add_test(tc_affine_scale_2, affine_scale_2);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *sr;
  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
  return 0;
}
